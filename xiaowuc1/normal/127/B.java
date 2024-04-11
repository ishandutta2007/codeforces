import java.util.*;
public class A127 {
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] list = new int[n];
		for(int i = 0; i < n; i++)
			list[i] = scan.nextInt();
		int[] go = new int[101];
		for(int out: list) {
			go[out]++;
		}
		for(int i = 0; i < go.length; i++)	{
			go[i] >>= 1;
		}
		int ret = 0;
		for(int i = 0; i < go.length; i++)	{
			for(int j = i+1; j < go.length; j++)	{
				while(go[i] > 0 && go[j] > 0)	{
					ret++;
					go[i]--;
					go[j]--;
				}
			}
			while(go[i] >= 2)	{
				go[i] -= 2;
				ret++;
			}
		}
		System.out.println(ret);
	}
}