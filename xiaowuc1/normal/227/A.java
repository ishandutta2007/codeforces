import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br;
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
	br = new BufferedReader(new InputStreamReader(System.in));
	int a = readInt();
	int b = readInt();
	int c = readInt();
	int d = readInt();
	int e = readInt();
	int f = readInt();
	int dirX = c-a;
	int dirY = d-b;
	int gcd = gcd(Math.abs(dirX), Math.abs(dirY));
	dirX /= gcd;
	dirY /= gcd;
	if(isInDir(c,d,e,f,dirX,dirY))
	    System.out.println("TOWARDS");
	else if(isInDir(c,d,e,f,-dirY,dirX))
	    System.out.println("LEFT");
	else
	    System.out.println("RIGHT");
    }

    public static boolean isInDir(int x1, int y1, int x2, int y2, int xD, int yD) {
	int propX = x2-x1;
	int propY = y2-y1;
	int gcd = gcd(Math.abs(propX), Math.abs(propY));
	propX /= gcd;
	propY /= gcd;
	return propX == xD && propY == yD;
    }

    public static int gcd(int a, int b) {
	if(a == 0)
	    return b;
	if(b == 0)
	    return a;
	return gcd(b,a%b);
    }

    public static String nextToken() throws IOException {
	while(st == null || !st.hasMoreTokens()) {
	    if(!br.ready()) {
		System.exit(0);
	    }
	    st = new StringTokenizer(br.readLine());
	}
	return st.nextToken();
    }

    public static int readInt() throws IOException {
	return Integer.parseInt(nextToken());
    }

}