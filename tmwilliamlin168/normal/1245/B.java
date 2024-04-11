import java.util.Scanner;
 
public class B {
 
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in =new Scanner(System.in);
		int T =in.nextInt();
		for(int i=0;i<T;i++) {
			int n=in.nextInt();
			int ra=in.nextInt();int pb=in.nextInt();int sc=in.nextInt();
			int count =(n+1)/2;
			String x=in.next();
		//	System.out.println(count);
			char c[]=x.toCharArray();
			int r=0,p=0,s=0;
			for(int j=0;j<c.length;j++) {
				if(c[j]=='R') {
				r++;
				}else if(c[j]=='P') {
					p++;
				}else {
					s++;
				}
			}
			int count2 =Math.min(ra, s)+Math.min(pb,r )+Math.min(sc, p);
 
			if(count2<count) {
				System.out.println("NO");
				continue;
			}else {
				System.out.println("YES");
				//StringBuilder sb =new StringBuilder();
				char[]xx=new char[c.length];
				for(int j=0;j<c.length;j++) {
					if(c[j]=='R'&&pb!=0) {
						xx[j]='P';pb--;
						//System.out.println("cnm");
					}else if(c[j]=='P'&&sc!=0) {
						xx[j]='S';sc--;		//				System.out.println("cnm");
 
					}else if(c[j]=='S'&&ra!=0) {
						ra--;xx[j]='R';
					}
			}
//				StringBuilder sb=new StringBuilder();
//				for(int j=0;j<c.length;j++) {
//					sb.append(xx[i]+"");
//				}
//				System.out.println(sb.toString());
			for(int j=0;j<c.length;j++) {
				if(xx[j]!='R'&&xx[j]!='P'&&xx[j]!='S') {
					if(pb>0) {
						xx[j]='P';pb--;
					}else if(sc>0) {
						xx[j]='S';sc--;
					}else {
						ra--;xx[j]='R';
					}
				}
			}
			StringBuilder sb=new StringBuilder();
			for(int j=0;j<c.length;j++) {
				sb.append(xx[j]+"");
			}
			System.out.println(sb.toString());
				
		}
	}
	}
}