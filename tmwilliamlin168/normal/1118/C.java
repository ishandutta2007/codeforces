import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	
	private static int[][] output = new int[100][100];	
	
	public static void main(String[] args) {							
		
		Scanner scan = new Scanner(System.in);

		int i , j , n = scan.nextInt();
		Map<Integer , Integer> map = new HashMap<>();
		for (i = 1;i <= n * n;i ++) {
			int value = scan.nextInt();
			map.put(value , map.getOrDefault(value , 0) + 1);			
		}
		
		if (n % 2 == 0) {
			Queue<Integer> queue = new LinkedList<>();					
			for (Map.Entry<Integer , Integer> entry : map.entrySet()) {
				int cnt = entry.getValue();			
				if (cnt % 4 != 0) {
					System.out.println("NO");
					return;					
				}			
				for (i = 0;i < cnt / 4;i ++) {
					queue.add(entry.getKey());				
				}
			}			
			for (i = 1;i <= n / 2;i ++) {
				for (j = 1;j <= n / 2;j ++) {
					output[i][j] = output[n - i + 1][j] = output[i][n - j + 1] = output[n - i + 1][n - j + 1] = queue.poll();
				}
			}
		} else {
			int remain = - 1;	
			Queue<Integer> fourQueue = new LinkedList<>() , twoQueue = new LinkedList<>();			
			for (Map.Entry<Integer , Integer> entry : map.entrySet()) {
				int cnt = entry.getValue();			
				if (cnt % 4 != 0) {
					int value = cnt % 4;
					if (value == 2) {
						twoQueue.add(entry.getKey());						
					} else if (value == 1) {
						if (remain < 0) {							
							remain = entry.getKey();
						} else {
							System.out.println("NO");
							return;							
						}
					} else if (value == 3) {
						twoQueue.add(entry.getKey());
						if (remain < 0) {
							remain = entry.getKey();
						} else {
							System.out.println("NO");
							return;
						}
					}
				}
				for (i = 0;i < cnt / 4;i ++) {
					fourQueue.add(entry.getKey());				
				}
			}	
			for (i = 1;i <= n / 2;i ++) {
				for (j = 1;j <= n / 2;j ++) {
					if (fourQueue.isEmpty()) {
						System.out.println("NO");
						return;
					} else {
						int value = fourQueue.poll();
						output[i][j] = output[n - i + 1][j] = output[i][n - j + 1] = output[n - i + 1][n - j + 1] = value;					
					}
				}
			}
			for (i = 1;i <= n / 2;i ++) {
				if (twoQueue.isEmpty()) {
					if (!fourQueue.isEmpty()) {
						int value = fourQueue.poll();
						twoQueue.add(value);
						twoQueue.add(value);	
					}
				} 
				if (twoQueue.isEmpty()) {
					System.out.println("NO");
					return;					
				} else {
					output[i][(n + 1) / 2] = output[n - i + 1][(n + 1) / 2] = twoQueue.poll();
				}
			}
			for (j = 1;j <= n / 2;j ++) {
				if (twoQueue.isEmpty()) {
					if (!fourQueue.isEmpty()) {
						int value = fourQueue.poll();
						twoQueue.add(value);
						twoQueue.add(value);						
					}
				} 
				if (twoQueue.isEmpty()) {
					System.out.println("NO");
					return;					
				} else {
					output[(n + 1) / 2][j] = output[(n + 1) / 2][n - j + 1] = twoQueue.poll();
				}
			}
			output[(n + 1) / 2][(n + 1) / 2] = remain;
		}
		
		System.out.println("YES");
		for (i = 1;i <= n;i ++) {
			StringBuilder builder = new StringBuilder();
			for (j = 1;j <= n;j ++) {
				if (j > 1) {
					builder.append(" ");
				}
				builder.append(output[i][j]);
			}
			System.out.println(builder.toString());
		}

	}

    
}