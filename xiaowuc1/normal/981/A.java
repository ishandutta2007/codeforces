import java.util.*;
public class Lewclass {
    public static void main(String[] args) throws Exception {
        Scanner lewin = new Scanner(System.in);
        String lewout = lewin.nextLine();
        int lewint = 0;
        for(int LEWI = 0; LEWI < lewout.length(); LEWI++) {
            for(int LEWJ = LEWI + 1; LEWJ <= lewout.length(); LEWJ++) {
                lewint = Math.max(lewint, !isLewout(lewout.substring(LEWI, LEWJ)) ? LEWJ - LEWI : 0);
            }
        }
        System.out.println(lewint);
    }
    public static boolean isLewout(String lewin) {
        return lewin.length() <= 1 ? true : lewin.charAt(0) == lewin.charAt(lewin.length()-1)
 && isLewout(lewin.substring(1, lewin.length()-1));    }
}