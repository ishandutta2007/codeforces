import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Arrays;

public class E {
	static int log;
	static int p;
	static int n;
	static int [] vals;
	static int MOD = 1000000007;
	public static void main(String[] args) throws IOException {
		Reader sc = new Reader();
		int t = sc.nextInt();
		StringBuilder sb=  new StringBuilder();
		while(t>0) {
			t--;
			 n= sc.nextInt();
			 p = sc.nextInt();
			vals = new int[n];
			for(int i=0;i<n;i++) {
				vals[i] = sc.nextInt();
			}
			log =0;
			long x = 1;
			if(p>1) {
				while(x<=n) {
					x*=(long) p;
					log++;
				}
			}
			else {
				sb.append(n%2);
				sb.append("\n");
				continue;
			}
			
			//check if this rigt
			Arrays.sort(vals);
			
			int i = n-1;
			while(i>=0) {
				int next = findIndex(i);
				if(next==-1) {
					break;
				}
				next--;
				i = next;
			}
			if(i<0) {
				sb.append(0);
				sb.append("\n");
				continue;
			}
			long a= exp(p,vals[i]);
			long b = 0;
			for(int j=0;j<=(i-1);j++) {
				b+=exp(p,vals[j]);
				b%=MOD;
			}
			if(b<0) b+=MOD;
			if(a<0) a+=MOD;
			long ans = a-b;
			ans%=MOD;
			if(ans<0) ans+=MOD;
			sb.append(ans);
			sb.append("\n");
			continue;

			
		}
		System.out.println(sb.toString());
		

		
	}
	
	static int findIndex(int i) {
		if(i==0) return -1; //?
		//choose if we do -1 or stay the same at each step
		int pow = vals[i];
		
		int k = pow-vals[i-1];
		if(k>=log) {
			return -1; //?
		}
		
		long needed = (long) Math.pow(p,k);
		int curr = vals[i-1];
		for(int j=i-1;j>=0;j--) {
			long mult = curr-vals[j];
			if(mult>=log) {
				return -1;//check if we need to do this
			}
			mult = (long) Math.pow(p,mult);
			needed = (long) needed*mult;
			curr = vals[j];
			if(needed>=(n)) {
				return -1;
			}
			
			needed--;
			if(needed==0) {
				return j;
			}
			
			
		}
		return -1;
	}
	static long exp(int base,int power) {
		if(base==0) return 0;
		if(power==0) return 1;
		if(power==1) return (base+MOD)%MOD;
		long ans = exp(base,power/2);
		ans = (ans*ans+MOD)%MOD;
		if(power%2==1) ans = (ans*base+MOD)%MOD;
		return (ans+MOD)%MOD;
	}
	static class Reader 
    { 
        final private int BUFFER_SIZE = 1 << 16; 
        private DataInputStream din; 
        private byte[] buffer; 
        private int bufferPointer, bytesRead; 
  
        public Reader() 
        { 
            din = new DataInputStream(System.in); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public Reader(String file_name) throws IOException 
        { 
            din = new DataInputStream(new FileInputStream(file_name)); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public String readLine() throws IOException 
        { 
            byte[] buf = new byte[64]; // line length 
            int cnt = 0, c; 
            while ((c = read()) != -1) 
            { 
                if (c == '\n') 
                    break; 
                buf[cnt++] = (byte) c; 
            } 
            return new String(buf, 0, cnt); 
        } 
  
        public int nextInt() throws IOException 
        { 
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
  
        public long nextLong() throws IOException 
        { 
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
  
        public double nextDouble() throws IOException 
        { 
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
  
        private void fillBuffer() throws IOException 
        { 
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE); 
            if (bytesRead == -1) 
                buffer[0] = -1; 
        } 
  
        private byte read() throws IOException 
        { 
            if (bufferPointer == bytesRead) 
                fillBuffer(); 
            return buffer[bufferPointer++]; 
        } 
  
        public void close() throws IOException 
        { 
            if (din == null) 
                return; 
            din.close(); 
        } 
    } 
}