import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int[][] A = new int[N][M], B = new int[N][M];
		for (int n = 0; n < N; n++) {
			st = new StringTokenizer(br.readLine());
			for (int m = 0; m < M; m++) {
				A[n][m] = Integer.parseInt(st.nextToken());
			}
		}
		for (int n = 0; n < N; n++) {
			st = new StringTokenizer(br.readLine());
			for (int m = 0; m < M; m++) {
				B[n][m] = Integer.parseInt(st.nextToken());
			}
		}
		for (int n = 0; n < N; n++) {
			int a = 0, b = 0;
			for (int m = 0; m < M; m++) {
				a ^= A[n][m];
				b ^= B[n][m];
			}
			if (a != b) {
				System.out.println("No");
				return;
			}
		}
		for (int m = 0; m < M; m++) {
			int a = 0, b = 0;
			for (int n = 0; n < N; n++) {
				a ^= A[n][m];
				b ^= B[n][m];
			}
			if (a != b) {
				System.out.println("No");
				return;
			}
		}
		System.out.println("Yes");

	}

}