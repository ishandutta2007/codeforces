import java.util.Scanner;

public class EmailFromPolycarp {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = Integer.parseInt(scanner.nextLine());
        for (int c = 0; c < t; c++) {
            String first = scanner.nextLine();
            String second = scanner.nextLine();
            int ix = 0;
            boolean works = true;
            for (char chara : second.toCharArray()) {
                if (ix < first.length() && chara == first.charAt(ix)) {
                    ix++;
                } else if (ix > 0 && chara == first.charAt(ix - 1)) {
                    continue;
                } else {
                    works = false;
                    break;
                }
            }
            if (ix != first.length()) {
                works = false;
            }
            System.out.println(works ? "YES" : "NO");
        }
    }
}