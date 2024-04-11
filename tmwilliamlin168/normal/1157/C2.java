import java.util.*;
import java.io.*;

public class IncreasingSubsequence
{

	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n = scan.nextInt();
		int[] arr = new int[n];
		for(int i = 0; i < n; i++)
			arr[i] = scan.nextInt();
		int[] prl = new int[n];
		for(int i = n-2; i >= 0; i--)
			if(arr[i] < arr[i+1]) prl[i] = prl[i+1]+1;
		int[] prr = new int[n];
		for(int i = 1; i < n; i++)
			if(arr[i] < arr[i-1]) prr[i] = prr[i-1]+1;
		ArrayList<Character> ans = new ArrayList<Character>();
		int last = 0;
		int left = 0;
		int right = n-1;
		while(left <= right){
			int a = arr[left];
			int b = arr[right];
			if(a <= last && b <= last) break;
			if(a <= last){
				ans.add('R');
				last = arr[right];
				right--;
			}
			else if(b <= last){
				ans.add('L');
				last = arr[left];
				left++;
			}
			else if(a == b){
				if(prl[left] > prr[right]){
					ans.add('L');
					last = arr[left];
					left++;
				}
				else{
					ans.add('R');
					last = arr[right];
					right--;
				}
			}
			else{
				if(a < b){
					ans.add('L');
					last = arr[left];
					left++;
				}
				else{
					ans.add('R');
					last = arr[right];
					right--;
				}
			}
		}
		out.println(ans.size());
		for(int i = 0; i < ans.size(); i++) out.print(ans.get(i));
		out.println();
		out.flush();
	}
}