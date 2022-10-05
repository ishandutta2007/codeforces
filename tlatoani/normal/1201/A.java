import java.util.Scanner;

public class ImportantExam {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        in.nextLine();
        int[][] choices = new int[m][5];
        for (int i = 0; i < n; i++) {
            String test = in.nextLine();
            for (int j = 0; j < m; j++) {
                choices[j][test.charAt(j) - 'A']++;
            }
        }
        int answer = 0;
        for (int j = 0; j < m; j++) {
            int max = 0;
            for (int k = 0; k < 5; k++) {
                max = Math.max(max, choices[j][k]);
            }
            answer += max * in.nextInt();
        }
        System.out.println(answer);
    }
}