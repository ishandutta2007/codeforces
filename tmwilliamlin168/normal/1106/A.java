import java.io.*;
import java.util.*;

public class CF1106A {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		char[][] cc = new char[n][n];
		for (int i = 0; i < n; i++)
			br.readLine().getChars(0, n, cc[i], 0);
		int k = 0;
		for (int i = 1; i + 1 < n; i++)
			for (int j = 1; j + 1 < n; j++)
				if (cc[i][j] == 'X' && cc[i - 1][j - 1] == 'X' && cc[i + 1][j - 1] == 'X' && cc[i - 1][j + 1] == 'X' && cc[i + 1][j + 1] == 'X')
					k++;
		System.out.println(k);
	}
}