import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StreamTokenizer;
import java.util.Arrays;

public class Main {
	static StreamTokenizer st=new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
	public static void main(String[] args) {
		int n=nextInt();
		int z=nextInt();
		int a[]=new int[n];
		for(int i=n-1;i>=0;i--){
			a[i]=nextInt();
		}
		Arrays.sort(a);
		int j=n/2;
		int ans=0;
		for(int i=0;i<n/2;i++){
			for(;j<n;j++){
				if(a[j]-a[i]>=z){
					ans++;
					j++;
					break;
				}
			}
		}
		System.out.println(ans);
	}
	static int nextInt(){
		try {
			st.nextToken();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return (int)st.nval;
	}
}