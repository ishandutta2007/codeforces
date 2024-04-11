//package round38;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class F {
	Scanner in;
	PrintWriter out;
//	String INPUT = "2 aba abac";
//	String INPUT = "3 artem nik max";
	String INPUT = "";
	
	String[] dic;
	void solve()
	{
		int n = ni();
		dic = new String[n];
		for(int i = 0;i < n;i++){
			dic[i] = in.next();
		}
		
		Map<String, Info> word = new HashMap<String, Info>();
		for(int i = 0;i < n;i++){
			for(int j = 0;j < dic[i].length();j++){
				for(int k = j + 1;k <= dic[i].length();k++){
					word.put(dic[i].substring(j, k), null);
				}
			}
		}
		
		String[][] q = new String[31][450*30];
		int[] ps = new int[31];
		for(String key : word.keySet()){
			int len = key.length();
			q[len][ps[len]++] = key;
		}
		
		outer:
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(j != i && dic[j].indexOf(dic[i]) > -1 && !dic[j].equals(dic[i])){
					continue outer;
				}
			}
			word.put(dic[i], new Info(0, score(dic[i]), false));
		}
		for(int i = 30;i >= 1;i--){
			for(int j = 0;j < ps[i];j++){
				String key = q[i][j];
				if(word.get(key) == null){
					int sc = score(key);
					boolean lose = true;
					int lof = 0;
					int los = 0;
					int wof = 0;
					int wos = 0;
					for(int k = 0;k < n;k++){
						for(int l = dic[k].indexOf(key, 0); l != -1;l = dic[k].indexOf(key, l+1)){
							if(l > 0){
								Info info = word.get(dic[k].substring(l-1, l+i));
								lose &= info.win;
								if(info.win){
									if(lof < info.second || (lof == info.second && los > info.first)){
										los = info.first;
										lof = info.second;
									}
								}else{
									if(wof < info.second || (wof == info.second && wos > info.first)){
										wos = info.first;
										wof = info.second;
									}
								}
							}
							if(l+i+1 <= dic[k].length()){
								Info info = word.get(dic[k].substring(l, l+i+1));
								lose &= info.win;
								if(info.win){
									if(lof < info.second || (lof == info.second && los > info.first)){
										los = info.first;
										lof = info.second;
									}
								}else{
									if(wof < info.second || (wof == info.second && wos > info.first)){
										wos = info.first;
										wof = info.second;
									}
								}
							}
						}
					}
					if(lose){
						word.put(key, new Info(lof, los + sc, !lose));
					}else{
						word.put(key, new Info(wof, wos + sc, !lose));
					}
				}
			}
		}
		
//		for(Map.Entry<String, Info> entry : word.entrySet()){
//			tr(entry.getKey(), entry.getValue());
//		}
//
		{
			boolean lose = true;
			int lof = 0;
			int los = 0;
			int wof = 0;
			int wos = 0;
			for(int k = 0;k < n;k++){
				for(int l = 0; l < dic[k].length();l++){
					Info info = word.get(dic[k].substring(l, l+1));
					lose &= info.win;
					if(info.win){
						if(lof < info.second || (lof == info.second && los > info.first)){
							los = info.first;
							lof = info.second;
						}
					}else{
						if(wof < info.second || (wof == info.second && wos > info.first)){
							wos = info.first;
							wof = info.second;
						}
					}
				}
			}
			out.println(!lose ? "First" : "Second");
			if(lose){
				out.println(lof + " " + los);
			}else{
				out.println(wof + " " + wos);
			}
		}
	}
	
	class Info
	{
		public boolean win;
		public int first;
		public int second;
		public Info(int first, int second, boolean win){
			this.first = first;
			this.second = second;
			this.win = win;
		}
		
		public String toString()
		{
			return Integer.toString(first) + " " + Integer.toString(second) + " " + Boolean.toString(win);
		}
	}
	
	int score(String sub)
	{
		int score = 0;
		int max = 0;
		for(char v : sub.toCharArray()){
			score += v - 'a' + 1;
			max = Math.max(max, v - 'a' + 1);
		}
		score *= max;
		
		for(String word : dic){
			if(word.indexOf(sub) > -1){
				score++;
			}
		}
		return score;
	}
	
	void run() throws Exception
	{
//		int n = 30;
//		StringBuilder sb = new StringBuilder(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append("aaaaaaaaaaaaaaaaaaaaaaaaaaaaa" + (char)('a' + (i*26/30)) + " ");
//		}
//		INPUT = sb.toString();

//		int n = 30;
//		StringBuilder sb = new StringBuilder(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append((char)('a' + (i * 26 / 30)) + " ");
//		}
//		INPUT = sb.toString();
//		tr(INPUT);

		
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new F().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}