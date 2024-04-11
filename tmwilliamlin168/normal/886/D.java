import java.io.*;
import java.util.*;

public class MainD {
	static StdIn in = new StdIn();
	static PrintWriter out = new PrintWriter(System.out);
	
	public static void main(String[] args) {
		int n=in.nextInt();
		List<String> ss = new ArrayList<String>();
		boolean[] contained = new boolean[n];
		int[] occ = new int[26];
		Arrays.fill(occ, -1);
		fa:
		for(int i=0; i<n; ++i) {
			String s=in.next();
			Set<Integer> intersects = new HashSet<Integer>();
			for(char c : s.toCharArray())
				if(occ[c-'a']!=-1)
					intersects.add(occ[c-'a']);
			for(int j : intersects)
				if(ss.get(j).contains(s))
					continue fa;
			List<Integer> intersects2 = new ArrayList<Integer>();
			for(int j : intersects) {
				if(!s.contains(ss.get(j)))
					intersects2.add(j);
				else
					contained[j]=true;
			}
			for(int j : intersects2) {
				int k=1, l=1;
				String s2=ss.get(j);
				while(k<s.length()&&s.charAt(k)!=s2.charAt(0))
					++k;
				for(; k+l<s.length(); ++l)
					if(s.charAt(k+l)!=s2.charAt(l))
						fk();
				if(k<s.length())
					s+=s2.substring(l);
				else {
					k=1;
					while(k<s2.length()&&s2.charAt(k)!=s.charAt(0))
						++k;
					for(l=1; k+l<s2.length(); ++l)
						if(s2.charAt(k+l)!=s.charAt(l))
							fk();
					if(k>=s2.length())
						fk();
					s=s2+s.substring(l);
				}
				contained[j]=true;
			}
			for(char c : s.toCharArray()) {
				if(occ[c-'a']==ss.size())
					fk();
				occ[c-'a']=ss.size();
			}
			ss.add(s);
		}
		for(int i=0; i<26; ++i)
			if(occ[i]!=-1&&ss.get(occ[i]).charAt(0)-'a'==i)
				out.print(ss.get(occ[i]));
		out.close();
	}
	
	static void fk() {
		System.out.println("NO");
		System.exit(0);
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