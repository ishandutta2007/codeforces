import java.util.Scanner;

public class project{
    public static boolean Check(int n, int k, int[] a, int x) {
        int i = 0; --k;
        while (i != n-1) {
            //System.out.println("i: ");
            //System.out.println(i);
            if (k == 0) return false;
            boolean ok = false;
            for(int j = Math.min(i+x+1, n-1); j > i; --j) {
                if (a[j] == 0) {
                    ok = true;
                    i = j;
                    --k;
                    break;
                }
            }
            if (ok == false) return false;
        }
        return true;
    }
    public static void main(String[]args){
    	Scanner sc = new Scanner(System.in);
    	int n = sc.nextInt(), k = sc.nextInt();
    	sc.nextLine();
    	String s = sc.nextLine();
    	int[] a = new int[n];
    	for(int i = 0; i < n; ++i) {
    	    a[i] = s.charAt(i)-'0';
            //System.out.println(a[i]);
    	}
    	
        //System.out.println(Check(n, k, a, 3));
        int lo = 0, hi = n, res = hi+1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (Check(n, k, a, mid) == true) {
                res = mid;
                hi = mid-1;
            } else lo = mid+1;
        }
        
        System.out.println(res);
    }
}