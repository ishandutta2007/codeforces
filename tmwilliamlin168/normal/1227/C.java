import java.util.*;
import java.io.*;
import java.math.*;
public class Main{
	static int mod = (int)1e9+7;
	public static PrintWriter out = new PrintWriter (new BufferedOutputStream(System.out));
	public static void main(String sp[])throws IOException{
		FastReader sc = new FastReader();
		int t = sc.nextInt();
		while(t-->0){
			int n = sc.nextInt();
			int k = sc.nextInt();
			String st = sc.next();
			char arr[] = st.toCharArray();
			StringBuilder sb = new StringBuilder();
			int count=0;
			
			int balance = 0;
			int a=0;
			int b=0;
			int index=0;
			for(int j=0;j<k-1;j++){
				int open =0;
				int close =0;
				for(int i=index;i<=index;i++){
					char ch = arr[i];
					if(ch=='('){
						if(arr[i+1]==')')
							break;
						else{
							for(int l=i+1;l<n;l++){
								if(arr[l]==')'){
									arr = swap(i, l, arr);
									sb.append((i+2)+" "+(l+1)+"\n");
									count++;
									break;
								}
							}
							close++;
						}
						if(close-open==0){
							break;
						}
					}else{
						for(int m=i+1;m<n;m++){
							if(arr[m]=='('){
							arr = swap(i,m,arr);
							sb.append((i+1)+" "+(m+1)+"\n");
							count++;
							break;}
						}
					}
				}
				index+=2;
			}
			int diff = n-((k-1)*2);
			int mid = diff/2;
			for(int i=(k-1)*2;i<n;i++){
				if(arr[i]=='(')
					mid--;
				if(arr[i]==')'){
					for(int l=i+1;l<n;l++){
						if(arr[l]=='('){
							arr = swap(i,l,arr);
							sb.append((i+1)+" "+(l+1)+"\n");
							count++;
							break;
						}
					}
					mid--;
				}
				
				if(mid==0)
					break;
			}
			System.out.println(count);
			System.out.print(sb.toString());
		
		}
	}
	
		public static char[] swap(int a, int b, char arr[]){
			for(int i=a, j=b; i<=j;i++, j--){
				char hold = arr[i];
				arr[i] = arr[j];
				arr[j] = hold;
			}
			return arr;
		}
	
	
		public static class comp implements Comparator<pair>{
		public int compare(pair o1, pair o2){
			if(o1.l==o2.l)
				return o1.r-o2.r;
			return o1.l-o2.l;
		}
	}
	
	
	public static class pair{
		int l;
		int r;
	}
	
 
	
	public static long sum(long a, long d, long n){
		
		long total = ((n)*((2*a)+(n-1)*d))/2;
		return total;
	}
	
	public static class trie{
		char ch;
		HashMap<Character,trie> hm = new HashMap<>();
		int count;
		boolean isterminal;
	}
	
	
	public static int partition(int [] arr, int s, int e){
		
		int index=s;
		int pivot = arr[e];
		for(int i=s;i<=e-1;i++){
			if(arr[i]<=pivot){
				arr = swap(arr, index, i);
				index++;
			}
		}
		swap(arr,index,e);
		print(arr);
		return index;
	}
	
	public static int[] swap(int[] arr, int low, int high){
		int temp = arr[low];
		arr[low]=arr[high];
		arr[high]=temp;
		return arr;
	}
	
	
	public static long gcd(long a, long b){
		if(a==0)
			return b;
		
		return gcd(b%a,a);
	}
	
	public static void print(int[] arr){
		for(int i=0;i<arr.length;i++)
			System.out.print(arr[i]+" ");
		System.out.println();
	}
	
 
	public static class FastReader {
		BufferedReader br;
		StringTokenizer st;
	
 
		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
 
		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (Exception r) {
					r.printStackTrace();
				}
			}
			return st.nextToken();
		}
 
		int nextInt() {
			return Integer.parseInt(next());//converts string to integer
		}
 
		double nextDouble() {
			return Double.parseDouble(next());
		}
 
		long nextLong() {
			return Long.parseLong(next());
		}
 
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (Exception r) {
				r.printStackTrace();
			}
			return str;
		}
	}
	
}