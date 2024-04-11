import java.util.Arrays;
import java.util.Scanner;
public class A_578
{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.nextLine();
		String str = sc.nextLine();
		char[] ch = str.toCharArray();
		int[] ar = new int[10];
		for (int i = 0 ; i < ch.length ; i++){
			if (ch[i]=='L'){
				for (int j = 0 ; j < 10 ; j++){
					if (ar[j]==0){
						ar[j] = 1;
						break;
					}
				}
			}
			else if (ch[i]=='R')
			{
				for (int j = 9 ; j >=0 ; j--){
					if (ar[j]==0){ 
						ar[j]=1; 
						break;
					}
				}
			}
			else
			{
				int idx = ch[i] - '0';
				ar[idx] = 0;
			}
		}
		for (int i = 0 ; i < 10 ; i++)
			System.out.print(ar[i]);
 
	}
}