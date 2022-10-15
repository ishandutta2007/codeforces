import java.io.*;
import java.util.*;

public class MainF {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	//static long M=1152921504606846883L;
	static long M=(long)1e9+9;
	static long[] p10, hash;
	static char[] s;
	
	public static void main(String[] args) {
		s = in.next().toCharArray();
		if(s[0]=='0'&&s[1]=='0'&&s[2]=='0') {
			System.out.println("0+0=0");
			return;
		}
		int n=s.length;
		p10 = new long[n];
		hash = new long[n];
		p10[0]=1;
		//inv10[1]=345876451382054065L;
		p10[1]=10;
		hash[0]=s[0]-'0';
		hash[1]=hash[0]*10+s[1]-'0';
		for(int i=2; i<n; ++i) {
			p10[i]=p10[i-1]*10%M;
			hash[i]=hash[i-1]*10%M+s[i]-'0';
		}
		for(int k=n/3;k<=Math.min(n/2+1, n-2); ++k) {
			int j1 = k-1;
			int j2 = n-k-1;
			int i3 = n-k;
			int j3 = n-1;
			if(0<=j1&&k<=j2&&i3<=j3&&(0==j1||s[0]!='0')&&(k==j2||s[k]!='0')&&(i3==j3||s[i3]!='0')&&(hash(0, j1)+hash(k, j2))%M==hash(i3, j3)) {
				System.out.println(new String(s, 0, j1-0+1)+"+"+new String(s, k, j2-k+1)+"="+new String(s, i3, j3-i3+1));
				System.exit(0);
			}
			int j11 = k-2;
			int i2 = k-1;
			int j21 = n-k-1;
			int i31 = n-k;
			int j31 = n-1;
			if(0<=j11&&i2<=j21&&i31<=j31&&(0==j11||s[0]!='0')&&(i2==j21||s[i2]!='0')&&(i31==j31||s[i31]!='0')&&(hash(0, j11)+hash(i2, j21))%M==hash(i31, j31)) {
				System.out.println(new String(s, 0, j11-0+1)+"+"+new String(s, i2, j21-i2+1)+"="+new String(s, i31, j31-i31+1));
				System.exit(0);
			}
			int j12 = n-2*k-1;
			int i21 = n-2*k;
			int j22 = n-k-1;
			int i32 = n-k;
			int j32 = n-1;
			if(0<=j12&&i21<=j22&&i32<=j32&&(0==j12||s[0]!='0')&&(i21==j22||s[i21]!='0')&&(i32==j32||s[i32]!='0')&&(hash(0, j12)+hash(i21, j22))%M==hash(i32, j32)) {
				System.out.println(new String(s, 0, j12-0+1)+"+"+new String(s, i21, j22-i21+1)+"="+new String(s, i32, j32-i32+1));
				System.exit(0);
			}
			int j13 = n-2*k;
			int i22 = n-2*k+1;
			int j23 = n-k-1;
			int i33 = n-k;
			int j33 = n-1;
			if(0<=j13&&i22<=j23&&i33<=j33&&(0==j13||s[0]!='0')&&(i22==j23||s[i22]!='0')&&(i33==j33||s[i33]!='0')&&(hash(0, j13)+hash(i22, j23))%M==hash(i33, j33)) {
				System.out.println(new String(s, 0, j13-0+1)+"+"+new String(s, i22, j23-i22+1)+"="+new String(s, i33, j33-i33+1));
				System.exit(0);
			}
		}
	}
	
	static long hash(int i, int j) {
		if(i==0)
			return hash[j];
		return (hash[j]-hash[i-1]*p10[j-i+1]%M+M)%M;
	}
	
	interface Input {
		public String next();
		public String nextLine();
		public int nextInt();
		public long nextLong();
		public double nextDouble();
	}
	static class StdIn implements Input {
		final private int BUFFER_SIZE = 1 << 16;
		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;
		public StdIn() {
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
		public StdIn(InputStream in) {
			try{
				din = new DataInputStream(in);
			} catch(Exception e) {
				throw new RuntimeException();
			}
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
		public String next() {
			int c;
			while((c=read())!=-1&&(c==' '||c=='\n'||c=='\r'));
			StringBuilder s = new StringBuilder();
			while (c != -1)
			{
				if (c == ' ' || c == '\n'||c=='\r')
					break;
				s.append((char)c);
				c=read();
			}
			return s.toString();
		}
		public String nextLine() {
			int c;
			while((c=read())!=-1&&(c==' '||c=='\n'||c=='\r'));
			StringBuilder s = new StringBuilder();
			while (c != -1)
			{
				if (c == '\n'||c=='\r')
					break;
				s.append((char)c);
				c = read();
			}
			return s.toString();
		}
		public int nextInt() {
			int ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do
				ret = ret * 10 + c - '0';
			while ((c = read()) >= '0' && c <= '9');

			if (neg)
				return -ret;
			return ret;
		}
		public int[] readIntArray(int n) {
			int[] ar = new int[n];
			for(int i=0; i<n; ++i)
				ar[i]=nextInt();
			return ar;
		}
		public long nextLong() {
			long ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do
				ret = ret * 10 + c - '0';
			while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}
		public long[] readLongArray(int n) {
			long[] ar = new long[n];
			for(int i=0; i<n; ++i)
				ar[i]=nextLong();
			return ar;
		}
		public double nextDouble() {
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do
				ret = ret * 10 + c - '0';
			while ((c = read()) >= '0' && c <= '9');
			if (c == '.')
				while ((c = read()) >= '0' && c <= '9')
					ret += (c - '0') / (div *= 10);
			if (neg)
				return -ret;
			return ret;
		}
		private void fillBuffer() throws IOException {
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1)
				buffer[0] = -1;
		}
		private byte read() {
			try{
				if (bufferPointer == bytesRead)
					fillBuffer();
				return buffer[bufferPointer++];
			} catch(IOException e) {
				throw new RuntimeException();
			}
		}
		public void close() throws IOException {
			if (din == null)
				return;
			din.close();
		}
	}
}