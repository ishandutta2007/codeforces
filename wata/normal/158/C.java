import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class C {
	Scanner sc = new Scanner(System.in);
	
	void run() {
		int n = sc.nextInt();
		ArrayList<String> path = new ArrayList<String>();
		while (n-- > 0) {
			String cmd = sc.next();
			if (cmd.equals("pwd")) {
				for (String s : path) {
					System.out.print("/" + s);
				}
				System.out.println("/");
			} else {
				String p = sc.next();
				if (p.startsWith("/")) {
					path.clear();
					p = p.substring(1);
				}
				String[] ss = p.split("/");
				for (String s : ss) {
					if (s.equals("..")) {
						path.remove(path.size() - 1);
					} else {
						path.add(s);
					}
				}
			}
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new C().run();
	}
}