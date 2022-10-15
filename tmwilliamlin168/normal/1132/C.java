import java.io.*;
import java.util.*;

public class A{

	public static void main(String[] args) throws IOException {
		Scanner sc=new Scanner();
		PrintWriter out=new PrintWriter(System.out);
		int n=sc.nextInt(),q=sc.nextInt();
		int []a=new int [n+1],l=new int [q],r=new int [q];
		for(int i=0;i<q;i++) {
			l[i]=sc.nextInt()-1;
			r[i]=sc.nextInt()-1;
			a[l[i]]++;
			a[r[i]+1]--;
			
		}
		int []ones=new int [n],twos=new int [n];
		int sum=0,col=0;
		for(int i=0;i<n;i++) {
			sum+=a[i];
			a[i]=sum;
			if(i>0) {
				ones[i]=ones[i-1];
				twos[i]=twos[i-1];
			}
			if(sum==1)
				ones[i]++;
			else if(sum==2)
				twos[i]++;
			if(sum>0)
				col++;
				
		}
		int ans=0;
		for(int i=0;i<q;i++)
			for(int j=0;j<q;j++)
			{
				if(i==j || l[i]>l[j])
					continue;
				int curr=col;
			    int l1=l[i],r1=r[i],l2=l[j],r2=r[j];
			    if(l2<=r1) //intersection
			    {
			        int min=Math.min(r1,r2),max=r1+r2-min;
			        
			       
                        curr-=get(l2,min,twos);
			            curr-=get(l1,l2-1,ones);
			            curr-=get(min+1,max,ones);
			     
			        
			    }
			    else
			    {
			        curr-=get(l1,r1,ones);
			        curr-=get(l2,r2,ones);
			    }
				ans=Math.max(ans, curr);
				
			}
		out.println(ans);
		out.close();

	}
	static int get(int l,int r,int []a) {
		
		if(l>r)
			return 0;
		int ans=a[r];
		if(l>0)
			ans-=a[l-1];
		return ans;
	}
	static class Scanner
	{
		BufferedReader br;
		StringTokenizer st;
		Scanner(){
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		Scanner(String fileName) throws FileNotFoundException{
			br=new BufferedReader(new FileReader(fileName));
		}
		String next() throws IOException {
			while(st==null || !st.hasMoreTokens())
				st=new StringTokenizer(br.readLine());
			return st.nextToken();
		}
		String nextLine() throws IOException {
			return br.readLine();
		}
		int nextInt() throws IOException{
			return Integer.parseInt(next());
		}
		long nextLong()  throws NumberFormatException, IOException {
			return Long.parseLong(next());
		}
		double nextDouble() throws NumberFormatException, IOException {
			return Double.parseDouble(next());
		}
	}
}