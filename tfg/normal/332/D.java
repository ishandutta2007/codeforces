import java.util.Scanner;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;



public class d {
	/*static private BigInteger combs[][];

	static private BigInteger comb(int n, int a) {
		return combs[n][a];
	}*/

	static private BigInteger fat[];

	static public void main(String[] args) {
		InputStream inputStream = System.in;
		InputReader in = new InputReader(inputStream);
		int n = in.nextInt();
		int k = in.nextInt();
		fat = new BigInteger[n + 1];
		fat[0] = new BigInteger("1");
		/*combs = new BigInteger[n + 1][n + 1];
		for(int i = 0; i < n; i++) {
			combs[i][0] = new BigInteger("1");
			combs[i][i] = new BigInteger("1");
			for(int j = 1; j <= i; j++) {
				combs[i + 1][j] = combs[i][j].add(combs[i][j - 1]);
			}
		}*/
		for(int i = 1; i <= n; i++) {
			fat[i] = fat[i - 1].multiply(new BigInteger("" + i));
		}
		int[] size = new int[n];
		long[] sum = new long[n];
		long[] sum2 = new long[n];
		for(int i = 0; i < n; i++) {
			size[i] = 0;
			sum[i] = 0;
			sum2[i] = 0;
		}
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				//System.out.println("(" + i + ", " + j + ")");
				int t = in.nextInt();
				//int t = 1;
				if(t != -1) {
					size[i]++;
					size[j]++;
					sum[i] += t;
					sum[j] += t;
				}
			}
		}
		for(int i = 0; i < n; i++) {
			//System.out.println(i + ": " + size[i] + ", " + sum[i]);
			sum2[size[i]] += sum[i];
		}
		BigInteger mul = fat[k - 1];
		BigInteger ans = new BigInteger("0");
		for(int i = k; i < n; i++) {
			if(sum2[i] > 0) {
				//System.out.println("on " + i + " has mul " + mul);
				ans = ans.add(mul.multiply(new BigInteger("" + sum2[i])));
			}
			mul = (mul.multiply(new BigInteger("" + i))).divide(new BigInteger("" + (i - k + 1)));
		}
		ans = ans.divide(fat[k - 1]);
		//System.out.println("ans is " + ans);
		ans = ans.multiply(fat[k].multiply(fat[n - k]));
		System.out.println(ans.divide(fat[n]));
	}

	static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}