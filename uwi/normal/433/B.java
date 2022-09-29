import java.util.*;


public class test {

    public static void main(String[] args)  {
        Scanner in = new Scanner(System.in) ;
        int n = in.nextInt() ;
        long x[] = new long[n] ;
        long y[] = new long[n] ;
        x[0] = y[0] = in.nextLong() ;
        for ( int i = 1 ; i < n ; ++i )
        {
        	y[i] = in.nextLong() ;
        	x[i] = y[i] + x[i-1] ;
        }
        Random gen = new Random();
        for(int i = 0;i < n-1;i++){
            int j = gen.nextInt(n-i-1)+i+1;
            long d = y[i]; y[i] = y[j]; y[j] = d;
        }
        Arrays.sort(y);
        for ( int i = 1 ; i < n ; ++i )
        	y[i] += y[i-1] ;
        int m = in.nextInt() ;
        while ( m-- > 0 )
        {
        	int ch = in.nextInt() , l = in.nextInt() - 1 , r = in.nextInt() - 1 ;
        	if ( ch == 1 )
        		{
        			System.out.println(l > 0 ? x[r] - x[l-1] : x[r]) ;
        		}
        	else
        	{
    			System.out.println(l > 0 ? y[r] - y[l-1] : y[r]) ;
    		}
        }
        in.close();
	}
}