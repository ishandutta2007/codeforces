//package round363;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.time.Instant;
import java.time.LocalDateTime;
import java.time.ZoneId;
import java.time.ZoneOffset;
import java.util.Arrays;
import java.util.Date;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
//		LocalDateTime ldtt = LocalDateTime.of(1996, 2, 29, 23, 59, 59);
//		tr(ldtt.toEpochSecond(ZoneOffset.UTC));
		int s = ni();
		int m = ni();
		int h = ni();
		int d = ni();
		int date = ni();
		int month = ni();
		for(int Q = ni();Q > 0;Q--){
			long t = nl();
			Instant ins = new Date(t*1000L).toInstant();
			
			LocalDateTime ldt = LocalDateTime.ofInstant(ins, ZoneId.of("GMT"));
			ldt = ldt.plusSeconds(1L);
			if(after(ldt, h, m, s)){
				ldt = ldt.plusDays(1L).withHour(0).withMinute(0).withSecond(0);
			}
			while(true){
				if(ok(ldt, d, date, month)){
					break;
				}else{
					ldt = ldt.plusDays(1L).withHour(0).withMinute(0).withSecond(0);
				}
			}
			int hh = ldt.getHour();
			int mm = ldt.getMinute();
			int ss = ldt.getSecond();
			while(true){
				boolean ok = true;
				if(h != -1 && h != hh)ok = false;
				if(m != -1 && m != mm)ok = false;
				if(s != -1 && s != ss)ok = false;
				if(ok)break;
				if(++ss == 60){
					ss = 0;
					if(++mm == 60){
						mm = 0;
						hh++;
					}
				}
			}
			ldt = ldt.withHour(hh).withMinute(mm).withSecond(ss);
//			tr(ldt);
			out.println(ldt.toEpochSecond(ZoneOffset.UTC));
		}
	}
	
	boolean after(LocalDateTime ldt, int h, int m, int s)
	{
		int lh = h == -1 ? 23 : h;
		int lm = m == -1 ? 59 : m;
		int ls = s == -1 ? 59 : s;
		if(ldt.getHour() > lh ||
				ldt.getHour() == lh && ldt.getMinute() > lm ||
				ldt.getHour() == lh && ldt.getMinute() == lm && ldt.getSecond() > ls){
			return true;
		}else{
			return false;
		}
	}
	
	boolean ok(int val, int x)
	{
		if(x == -1)return true;
		if(val != x)return false;
		return true;
	}
	
	boolean ok(LocalDateTime ldt, int d, int date, int month)
	{
		if(d == -1 && date == -1 && month == -1)return true;
		if(month != -1 && ldt.getMonthValue() != month)return false;
		if(d == -1 && date == -1)return true;
		if(d != -1 && ldt.getDayOfWeek().getValue() == d)return true;
		if(date != -1 && ldt.getDayOfMonth() == date)return true;
		return false;
	}
	
	void run() throws Exception
	{
//		String INPUT = "0 0 12 -1 29 2\r\n" + 
//				"1000\r\n" + 
//				"825638399\r\n" + "";
//		for(int i = 0;i < 999;i++){
//			INPUT += "825638399\r\n";
//		}
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
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
	
	private long nl()
	{
		long num = 0;
		int b;
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