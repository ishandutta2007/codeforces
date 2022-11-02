import java.util.Scanner;


public class Main {

    public static int[] was=new int[1300000];
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        solve(in.nextInt(), in.nextInt(), in.nextInt());
        in.close();
    }
    
    static void solve(int a, int b, int c) {
        final int mod = 1073741824;
        int sum = 0;
        for (int i = 1; i <= a; i++)
            for (int j = 1; j <= b; j++)
                for (int k = 1; k <= c; k++)
                    sum = (sum + d(i*j*k)) % mod;
        System.out.print(sum);
    }
    
    static int d(int n) {
        if (was[n]!=0)return was[n];
        int result = 0;
        int sqrtN = (int) Math.sqrt(n);
        for (int i = 1; i <= sqrtN; i++)
            if(n % i == 0)
                result++;
        if (sqrtN * sqrtN == n) 
            result = 2 * result - 1;
        else
            result = 2 * result;
        was[n]=result;
        return result;
    }

}