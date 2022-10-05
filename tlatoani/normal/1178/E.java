import java.util.Scanner;

public class Archaeology {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        StringBuilder front = new StringBuilder();
        StringBuilder back = new StringBuilder();
        int i, j;
        for (i = 0, j = s.length() - 1; j - i >= 3;) {
            if (s.charAt(i) == s.charAt(j)) {
                front.append(s.charAt(i));
                back.append(s.charAt(j));
                i++;
                j--;
            } else if (s.charAt(i) == s.charAt(j - 1)) {
                front.append(s.charAt(i));
                back.append(s.charAt(i));
                i++;
                j -= 2;
            } else if (s.charAt(i + 1) == s.charAt(j)) {
                front.append(s.charAt(j));
                back.append(s.charAt(j));
                i += 2;
                j--;
            } else {
                front.append(s.charAt(i + 1));
                back.append(s.charAt(j - 1));
                i += 2;
                j -= 2;
            }
        }
        if (j > i && s.charAt(i) == s.charAt(j)) {
            front.append(s.charAt(i));
            back.append(s.charAt(j));
        } else if (j - i == 2 && s.charAt(i) == s.charAt(j - 1)) {
            front.append(s.charAt(i));
            back.append(s.charAt(i));
        } else if (j - i == 2 && s.charAt(i + 1) == s.charAt(j)) {
            front.append(s.charAt(j));
            back.append(s.charAt(j));
        } else {
            front.append(s.charAt(i));
        }
        if (front.length() + back.length() >= s.length() / 2) {
            System.out.print(front);
            System.out.println(back.reverse());
        } else {
            System.out.println("IMPOSSIBLE");
        }
    }
}