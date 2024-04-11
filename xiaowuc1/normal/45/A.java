import java.io.*;
import java.util.*;
public class A45 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] list = new String[12];
        list[0] = "January";
        list[1] = "February";
        list[2] = "March";
        list[3] = "April";
        list[4] = "May";
        list[5] = "June";
        list[6] = "July";
        list[7] = "August";
        list[8] = "September";
        list[9] = "October";
        list[10] = "November";
        list[11] = "December";
        String s = br.readLine();
        int n = Integer.parseInt(br.readLine());
        for(int i = 0; i < 12; i++)
            if(s.equals(list[i]))
                System.out.println(list[(i+n)%12]);
    }
}