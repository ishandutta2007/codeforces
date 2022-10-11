import java.io.*;
import java.util.*;
public class B58 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        LinkedList<Integer> list = new LinkedList<Integer>();
        list.add(n);
        int c = 2;
        while(list.peekLast() != 1)     {
            if(list.peekLast() % c == 0)
                list.addLast(list.peekLast() / c);
            else
                c++;
        }
        StringBuilder sb = new StringBuilder();
        for(int x: list)
            sb.append(x + " ");
        System.out.println(sb.toString().trim());
    }
}