import java.io.*;
import java.util.*;
public class A63 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] name = new String[n];
        String[] status = new String[n];
        for(int i = 0; i < n; i++)  {
            StringTokenizer st = new StringTokenizer(br.readLine());
            name[i] = st.nextToken();
            status[i] = st.nextToken();
        }
        Set<String> a1 = new HashSet<String>();
        Set<String> a2 = new HashSet<String>();
        Set<String> a3 = new HashSet<String>();
        Set<String> a4 = new HashSet<String>();
        a1.add("rat");
        a2.add("woman");
        a2.add("child");
        a3.add("man");
        a4.add("captain");
        for(int i = 0; i < n; i++)  {
            if(a1.contains(status[i]))
                System.out.println(name[i]);
        }
        for(int i = 0; i < n; i++)  {
            if(a2.contains(status[i]))
                System.out.println(name[i]);
        }
        for(int i = 0; i < n; i++)  {
            if(a3.contains(status[i]))
                System.out.println(name[i]);
        }
        for(int i = 0; i < n; i++)  {
            if(a4.contains(status[i]))
                System.out.println(name[i]);
        }
    }
}