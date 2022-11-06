import java.util.Scanner;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        System.out.println(N % 2 == 0 ? "home" : "contest");
    }

}