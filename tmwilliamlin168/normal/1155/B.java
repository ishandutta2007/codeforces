import java.util.Scanner;

public class main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n =  sc.nextInt();
		String st =  sc.next();
		int length = st.length()-11+1;
		int cnt1=0;
		int cnt2=0;
		for(int i=0;i<length;i++){
			if(st.charAt(i)=='8'){
				cnt1++;
			}else{
				cnt2++;
			}
		}
		if(cnt1>cnt2){
			System.out.println("YES");
		}else{
			System.out.println("NO");
		}

	}

}