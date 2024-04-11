import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class B {
    Scanner sc = new Scanner(System.in);
    
    int[][] pp = {
            {1},
            {1},
            {1},
            {2},
            {1},
            {1},
            {1,2,7},
            {4},
            {3},
            {2},
            {1,2,10},
            {3,5,8},
            {1,11,12},
            {1},
            {10,12,15},
            {3},
            {7},
            {3,9,10},
            {3},
            {2},
            {1},
            {5},
            {2,5,11},
            {3},
            {13,15,23},
            {17,22,23},
            {3},
            {2},
            {9,10,27},
            {3},
            {2,7,16},
            {13},
            {8,12,17},
            {2},
            {11},
            {2,14,22},
            {5,6,27},
            {4},
            {23,27,29},
            {3},
            {30,31,34},
            {5,22,27},
            {18,35,39},
            {4,28,39},
            {18,31,40},
            {5},
            {1,9,19},
            {9},
            {17,31,34},
    };
    
    void run() {
        int k = sc.nextInt();
        for (int i = 0; i < k - 1; i++) {
            if (binarySearch(pp[k - 2], k - 1 - i) >= 0) System.out.print("1 ");
            else System.out.print("0 ");
        }
        System.out.println(1);
        for (int i = 0; i < k - 1; i++) {
            System.out.print("1 ");
        }
        System.out.println(1);
    }
    
    void debug(Object...os) {
        System.err.println(deepToString(os));
    }
    
    public static void main(String[] args) {
        new B().run();
    }
}