import java.io.InputStreamReader;
import java.util.Scanner;

public class D {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(new InputStreamReader(System.in));
        int t = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < t; i++) {
            char[][] board = new char[9][9];
            for (int j = 0; j < 9; j++) {
                String aRow = scanner.nextLine();
                for (int k = 0; k < 9; k++) {
                    board[j][k] = aRow.charAt(k);
                    if (board[j][k] == '1')
                        board[j][k] = '2';
                }
            }

            for (int j = 0; j < 9; j++) {
                StringBuilder stringBuilder = new StringBuilder();
                for (int k = 0; k < 9; k++) {
                    stringBuilder.append(board[j][k]);
                }
                System.out.println(stringBuilder.toString());
            }


        }
    }
}