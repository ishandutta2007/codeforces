import java.io.*;
import java.util.*;

public class Solution2 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long n=in.nextLong();
		if(n==0) {
			System.out.println(0);
			return;
		} else if(n<10) {
			System.out.println(1);
			return;
		}
		long[][][] dp1 = new long[18][10][10];
		int[][][] dp2 = new int[18][10][10];
		for(int i=0; i<10; ++i) {
			for(int j=1; j<10; ++j) {
				dp1[0][i][j]=1;
				if(i>j)
					dp2[0][i][j]=j-i;
			}
		}
		for(int i=1; i<=17; ++i) {
			for(int j=0; j<10; ++j) {
				for(int k=0; k<10; ++k) {
					int firstD=9, cK=k, maxD;
					while(firstD>=0) {
						maxD=Math.max(j, firstD);
						dp1[i][j][k]+=dp1[i-1][maxD][cK];
						cK=dp2[i-1][maxD][cK];
						if(cK==0&&firstD>0) {
							cK=10-maxD;
							++dp1[i][j][k];
						} else
							cK=10+cK;
						--firstD;
					}
					dp2[i][j][k]=cK-10;
				}
			}
		}
		long t=0, pow=1;
		for(int i=1; i<=17; ++i, pow*=10) {
			int firstD=(int)(n/(10*pow)%10), cK=(int)(n%10), maxD=0;
			//System.out.println(firstD+" "+cK);
			long cN=n/(10*pow);
			while((cN/=10)>0)
				maxD=Math.max((int)(cN%10), maxD);
			if(maxD==0&&firstD==0&&cK==0)
				break;
			while(firstD>=0) {
				int maxD2=Math.max(maxD, firstD);
				t+=dp1[i-1][maxD2][cK];
				cK=dp2[i-1][maxD2][cK];
				if(cK==0&&(firstD>0||maxD>0)) {
					cK=10-maxD2;
					++t;
				} else
					cK=10+cK;
				--firstD;
				n=n/(10*pow)*10*pow-10+cK;
				//System.out.println(n+" "+t);
			}
		}
		System.out.println(t);
	}
}