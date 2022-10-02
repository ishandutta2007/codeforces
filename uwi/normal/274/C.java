//package round168;
import java.awt.geom.Point2D;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;


public class C6 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
//	String INPUT = "3 0 0 1 1 2 2 ";
//	String INPUT = "4 0 0 0 2 2 2 2 0";
//	String INPUT = "4 0 1 0 -1 -2 0 4 0";
//	String INPUT = "4 0 0 4 8 8 0 4 3";
//	String INPUT = "20\r\n" + 
//			"3789 -1964\r\n" + 
//			"7033 -4086\r\n" + 
//			"2379 -7467\r\n" + 
//			"8609 -4677\r\n" + 
//			"-8359 8919\r\n" + 
//			"3391 8515\r\n" + 
//			"1368 2089\r\n" + 
//			"1898 2663\r\n" + 
//			"-9870 2524\r\n" + 
//			"5768 -1414\r\n" + 
//			"-7549 739\r\n" + 
//			"-3691 -1850\r\n" + 
//			"-7118 -3897\r\n" + 
//			"2204 3144\r\n" + 
//			"1191 8585\r\n" + 
//			"-6875 6888\r\n" + 
//			"4309 -5523\r\n" + 
//			"4816 5772\r\n" + 
//			"-9541 -2271\r\n" + 
//			"9337 7795";
	
	void solve()
	{
		int n = ni();
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++){
			co[i] = new int[]{ni(), ni()};
		}
		
		double max = -1;
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				inner:
				for(int k = j+1;k < n;k++){
					int cross = 
							(co[k][0]-co[i][0])*(co[j][1]-co[i][1])-
							(co[k][1]-co[i][1])*(co[j][0]-co[i][0]);
					if(cross == 0)continue;
					int dot =
							(co[k][0]-co[i][0])*(co[j][0]-co[i][0])+
							(co[k][1]-co[i][1])*(co[j][1]-co[i][1])
							;
					int dot2 =
							(co[k][0]-co[j][0])*(co[i][0]-co[j][0])+
							(co[k][1]-co[j][1])*(co[i][1]-co[j][1])
							;
					int dot3 =
							(co[i][0]-co[k][0])*(co[j][0]-co[k][0])+
							(co[i][1]-co[k][1])*(co[j][1]-co[k][1])
							;
					double[] ex = excircle2(co[i][0], co[i][1], co[j][0], co[j][1], co[k][0], co[k][1]);

					if(dot == 0){
						max = Math.max(max, go(i, j, k, co, ex));
					}else if(dot2 == 0){
						max = Math.max(max, go(j, k, i, co, ex));
					}else if(dot3 == 0){
						max = Math.max(max, go(k, i, j, co, ex));
					}else if(dot > 0 && dot2 > 0 && dot3 > 0){
						double eps = 1E-10;
						for(int l = 0;l < n;l++){
							if(Point2D.distance(ex[0], ex[1], co[l][0], co[l][1]) < ex[2]-eps){
								continue inner;
							}
						}
						max = Math.max(max, ex[2]);
					}
				}
			}
		}
		
		if(max == -1){
			out.println(-1);
		}else{
			out.printf("%.12f\n", max);
		}
	}
	
	double go(int k, int i, int j, int[][] co, double[] ex)
	{
		int n = co.length;
		int cross = 
				(co[k][0]-co[i][0])*(co[j][1]-co[i][1])-
				(co[k][1]-co[i][1])*(co[j][0]-co[i][0]);
		double r = ex[2];
		boolean found = false;
		for(int l = 0;l < n;l++){
			if(l != i & l != j && l != k){
				double cross2 = 
						(co[l][0]-co[i][0])*(co[j][1]-co[i][1])-
						(co[l][1]-co[i][1])*(co[j][0]-co[i][0]);
				if(cross2 * cross < 0){
					double dot2 = 
							(co[i][0]-co[l][0])*(co[j][0]-co[l][0])+
							(co[i][1]-co[l][1])*(co[j][1]-co[l][1]);
					if(dot2 == 0){
						found = true;
						break;
					}
				}
			}
		}
		if(!found)return -1;
		double eps = 1E-9;
		for(int l = 0;l < n;l++){
			if(Point2D.distance(ex[0], ex[1], co[l][0], co[l][1]) < r-eps){
				return -1;
			}
		}
		return r;
	}
	
	public static int ccw(double ax, double ay, double bx, double by, double tx, double ty){
		return (int)Math.signum((tx-ax)*(by-ay)-(bx-ax)*(ty-ay));
	}
	
	public static double[] excircle2(double ax, double ay, double bx, double by, double cx, double cy)
	{
		double A = (bx-cx)*(bx-cx)+(by-cy)*(by-cy);
		double B = (cx-ax)*(cx-ax)+(cy-ay)*(cy-ay);
		double C = (ax-bx)*(ax-bx)+(ay-by)*(ay-by);
		double D = A*(-A+B+C)+B*(A-B+C)+C*(A+B-C);
		double X = (A*(-A+B+C)*ax + B*(A-B+C)*bx + C*(A+B-C)*cx) / D;
		double Y = (A*(-A+B+C)*ay + B*(A-B+C)*by + C*(A+B-C)*cy) / D;
		double R = Math.sqrt((X-ax)*(X-ax)+(Y-ay)*(Y-ay));
//		double R = A*B*C/Math.sqrt((A+B+C)*(-A+B+C)*(A-B+C)*(A+B-C));
		return new double[]{X, Y, R};
	}
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new C6().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}