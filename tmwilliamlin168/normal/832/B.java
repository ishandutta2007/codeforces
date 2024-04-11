import java.io.*;
import java.util.*;

public class Main {
	
	//PLEASE HACK MY SOLUTION IT IS EASY TO UNDERSTAND

	public static void main(String[] args) {
		StdIn in = new StdIn();
		String goodChars = in.next();
		boolean[] isGood = new boolean[26];
		for(char c : goodChars.toCharArray())
			isGood[c-'a']=true;
		String pattern = in.next();
		String[] patterns = pattern.split("\\*");
		if(patterns.length==1&&pattern.endsWith("*"))
			patterns = new String[]{patterns[0], ""};
		int n=in.nextInt();
		StringBuilder output = new StringBuilder();
		for(int i=0; i<n; ++i) {
			String s = in.next();
			boolean sWorks=true;
			
			if(patterns.length==0) {
				for(int j=0; j<s.length(); ++j) {
					if(isGood[s.charAt(j)-'a']) {
						sWorks=false;
						break;
					}
				}
			} else if(patterns.length==2) {
				if(patterns[0].length()+patterns[1].length()>s.length())
					sWorks=false;
				if(sWorks) {
					for(int j=0; j<patterns[0].length(); ++j) {
						if(patterns[0].charAt(j)=='?'&&!isGood[s.charAt(j)-'a']) {
							sWorks=false;
							break;
						} else if(patterns[0].charAt(j)!='?'&&patterns[0].charAt(j)!=s.charAt(j)) {
							sWorks=false;
							break;
						}
					}
				}
				
				int start=s.length()-patterns[1].length();
				if(sWorks) {
					for(int j=0; j<patterns[1].length(); ++j) {
						if(patterns[1].charAt(j)=='?'&&!isGood[s.charAt(start+j)-'a']) {
							sWorks=false;
							break;
						} else if(patterns[1].charAt(j)!='?'&&patterns[1].charAt(j)!=s.charAt(start+j)) {
							sWorks=false;
							break;
						}
					}
				}
				
				if(sWorks) {
					for(int j=patterns[0].length(); j<start; ++j) {
						if(isGood[s.charAt(j)-'a']) {
							sWorks=false;
							break;
						}
					}
				}
			} else {
				if(patterns[0].length()!=s.length())
					sWorks=false;
				if(sWorks) {
					for(int j=0; j<s.length(); ++j) {
						if(patterns[0].charAt(j)=='?'&&!isGood[s.charAt(j)-'a']) {
							sWorks=false;
							break;
						} else if(patterns[0].charAt(j)!='?'&&patterns[0].charAt(j)!=s.charAt(j)) {
							sWorks=false;
							break;
						}
					}
				}
			}
			
			if(sWorks) {
			    output.append("YES\n");
			} else {
				output.append("NO\n");
			}
		}
		System.out.print(output);
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
		final private int STRING_SIZE = 1 << 6;
		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;

		public StdIn() {
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
		
		public StdIn(String filename) {
	        try{
	            din = new DataInputStream(new FileInputStream(filename));
	        } catch(Exception e) {
	            throw new RuntimeException();
	        }
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
		
		public String next() {
			char[] buf = new char[STRING_SIZE]; // string length
			int cnt = 0, c;
			while((c=read())!=-1&&(c==' '||c=='\n'||c=='\r'));
			StringBuilder s = new StringBuilder();
			while (c != -1)
			{
				if (c == ' ' || c == '\n'||c=='\r')
					break;
				buf[cnt++] = (char) c;
				if(cnt==buf.length) {
					s.append(buf);
					buf=new char[STRING_SIZE];
					cnt=0;
				}
				c=read();
			}
			return s.append(new String(buf, 0, cnt)).toString();
		}

		public String nextLine() {
			char[] buf = new char[STRING_SIZE]; // line length
			int cnt = 0, c;
			while((c=read())!=-1&&(c==' '||c=='\n'||c=='\r'));
			StringBuilder s = new StringBuilder();
			while (c != -1)
			{
				if (c == '\n'||c=='\r')
					break;
				buf[cnt++] = (char) c;
				if(cnt==buf.length) {
					s.append(buf);
					buf=new char[STRING_SIZE];
					cnt=0;
				}
				c = read();
			}
			return s.append(new String(buf, 0, cnt)).toString();
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
			{
				ret = ret * 10 + c - '0';
			}  while ((c = read()) >= '0' && c <= '9');

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
			do {
				ret = ret * 10 + c - '0';
			}
			while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}

		public double nextDouble() {
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();

			do {
				ret = ret * 10 + c - '0';
			}
			while ((c = read()) >= '0' && c <= '9');

			if (c == '.')
			{
				while ((c = read()) >= '0' && c <= '9')
				{
					ret += (c - '0') / (div *= 10);
				}
			}

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