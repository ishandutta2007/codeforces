import java.util.*;
public class main {
public static void main(String q[]) {
Scanner p = new Scanner(System.in);
int f = p.nextInt();
int m = p.nextInt();
int t = p.nextInt();
int n[] = new int[m];
int i, j, o = 0;
for (i = 0; i < f; ++i) {
String s = p.next();
for (j = 0; j < m; ++j) {
if (s.charAt(j) == 'Y') {
n[j] += 1;
}
}
}		
for (i = 0; i < m; ++i) {
if (n[i] >= t) {
o += 1;
}
}
System.out.println(o);
}
//kitten
}