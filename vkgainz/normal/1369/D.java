import java.util.Scanner;

public class D {
    static int MOD = 1000000007;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        long dp[][] = new long[2000001][2];
        dp[2][0] = 4;
        dp[2][1] = 0;

            dp[3][0] = 4;
            dp[3][1] = 4;


        //0 == free, 1 = taken
        for(int i=4;i<2000001;i++){
            dp[i][0] = Math.max(dp[i-1][0]+2*dp[i-2][0],4+dp[i-1][1]+2*dp[i-2][1]);
            dp[i][1] = dp[i-1][0]+2*dp[i-2][0];

            dp[i][0]%=MOD;
            dp[i][1]%=MOD;
        }
        while(t>0){
            t--;
            int n = sc.nextInt();


            System.out.println(dp[n-1][0]);
        }










    }
}