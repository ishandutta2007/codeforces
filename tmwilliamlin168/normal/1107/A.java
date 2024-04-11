import java.util.Scanner;

public class DigitsSequenceDividing
{
  public static void main(String[] args)
  {
    Scanner sc = new Scanner(System.in);
    int test = sc.nextInt();
    for (int i = 0; i < test; i++)
    {
      int size = sc.nextInt();
      String input = sc.next();
      if (input.charAt(0) >= input.charAt(1) && input.length() == 2)
      {
        System.out.println("NO");
      }
      else
      {
        System.out.println("YES");
        System.out.println(2);
        StringBuilder build = new StringBuilder();
        for (int j = 1; j < input.length(); j++)
        {
          build.append(input.charAt(j));
        }
        System.out.println(input.charAt(0) + " " + build.toString());
      }
    }
  }
}