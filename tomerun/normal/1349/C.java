import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static final int INF = 1 << 30;
	static Scanner sc = new Scanner(System.in);
	static int[] DR = new int[]{1, 0, -1, 0};
	static int[] DC = new int[]{0, 1, 0, -1};

	public static void main(String[] args) {
		int N = sc.nextInt();
		int M = sc.nextInt();
		int T = sc.nextInt();
		boolean[][] f = new boolean[N][M];
		for (int i = 0; i < N; i++) {
			char[] row = sc.next().toCharArray();
			for (int j = 0; j < M; j++) {
				f[i][j] = row[j] == '1';
			}
		}
		int[][] first = new int[N][M];
		for (int i = 0; i < N; i++) {
			Arrays.fill(first[i], INF);
		}
		ArrayList<Integer> q = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				for (int k = 0; k < 4; k++) {
					int nr = i + DR[k];
					int nc = j + DC[k];
					if (0 <= nr && nr < N && 0 <= nc && nc < M && f[i][j] == f[nr][nc]) {
						first[i][j] = 1;
					}
				}
				if (first[i][j] == 1) q.add((i << 10) | j);
			}
		}
		for (int i = 0; i < q.size(); i++) {
			int cr = q.get(i) >> 10;
			int cc = q.get(i) & 0x3FF;
			for (int j = 0; j < 4; j++) {
				int nr = cr + DR[j];
				int nc = cc + DC[j];
				if (0 <= nr && nr < N && 0 <= nc && nc < M && first[nr][nc] == INF) {
					first[nr][nc] = first[cr][cc] + 1;
					q.add((nr << 10) | nc);
				}
			}
		}
		PrintWriter writer = new PrintWriter(System.out);
		for (int i = 0; i < T; i++) {
			int qr = Integer.parseInt(sc.next()) - 1;
			int qc = Integer.parseInt(sc.next()) - 1;
			long p = Long.parseLong(sc.next());
			if (p < first[qr][qc] || first[qr][qc] == INF) {
				writer.println(f[qr][qc] ? 1 : 0);
			} else {
				writer.println(((p - first[qr][qc] + 1) % 2 == 1 ^ f[qr][qc]) ? 1 : 0);
			}
		}
		writer.flush();
	}


}