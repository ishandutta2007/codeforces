//package round43;

import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.BitSet;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class F {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int k = ni();
		int[][] link = new int[m][2];
		for(int i = 0;i < m;i++){
			int f = ni() - 1;
			int t = ni() - 1;
			if(f > t){
				int d = f; f = t;t = d;
			}
			link[i][0] = f;
			link[i][1] = t;
		}
		
		BitSet[] verkey = new BitSet[n]; // [] = 
		for(int i = 0;i < n;i++){
			verkey[i] = new BitSet();
		}
		for(int i = 0;i < m;i++){
			verkey[link[i][0]].set(i);
			verkey[link[i][1]].set(i);
		}
		
		Map<String, Integer> nameInd = new HashMap<String, Integer>();
		int[] ikeys = new int[m]; // [] = 
		BitSet[] team = new BitSet[n];
		for(int i = 0;i < n;i++)team[i] = new BitSet();
		int[] posteam = new int[n];
		Resident[] r = new Resident[k];
		BitSet start = new BitSet();
		for(int i = 0;i < k;i++){
			Resident re = new Resident();
			re.name = in.next();
			re.pos = ni() - 1;
			int u = ni();
			int[] keys = new int[u];
			for(int j = 0;j < u;j++){
				keys[j] = ni() - 1;
				ikeys[keys[j]] = i;
			}
			re.keys = keys;
			start.set(re.pos);
			r[i] = re;
			
			nameInd.put(re.name, i);
		}
		
		simulate(team, posteam, r, start, k, link, n, ikeys, verkey);
		
		int[] ikeys2 = new int[m]; // [] = 
		BitSet[] team2 = new BitSet[n];
		for(int i = 0;i < n;i++)team2[i] = new BitSet();
		int[] posteam2 = new int[n];
		Resident[] r2 = new Resident[k];
		BitSet start2 = new BitSet();
		for(int i = 0;i < k;i++){
			Resident re = new Resident();
			re.name = in.next();
			re.pos = ni() - 1;
			int u = ni();
			int[] keys = new int[u];
			for(int j = 0;j < u;j++){
				keys[j] = ni() - 1;
				ikeys2[keys[j]] = i;
			}
			re.keys = keys;
			start2.set(re.pos);
			r2[i] = re;
		}
		
		simulate(team2, posteam2, r2, start2, k, link, n, ikeys2, verkey);
		
		for(int i = 0;i < k;i++){
			Resident re2 = r2[i];
			int ind = nameInd.get(re2.name);
			Resident re = r[ind];
			if(!(posteam2[re.pos] == posteam2[re2.pos] && posteam[re.pos] == posteam[re2.pos])){
				out.println("NO");
				return;
			}
			int te2 = posteam2[re2.pos];
			int te = posteam[re.pos];
			
			{
				BitSet mkey = new BitSet();
				for(int xkey : re2.keys){
					mkey.set(xkey);
				}
				for(int j = team[te].nextSetBit(0);j != -1;j = team[te].nextSetBit(j+1)){
					for(int key : r[j].keys){
						mkey.clear(key);
					}
				}
				if(!mkey.isEmpty()){
					out.println("NO");
					return;
				}
			}
			
			{
				BitSet mkey = new BitSet();
				for(int xkey : re.keys){
					mkey.set(xkey);
				}
				for(int j = team2[te2].nextSetBit(0);j != -1;j = team2[te2].nextSetBit(j+1)){
					for(int key : r2[j].keys){
						mkey.clear(key);
					}
				}
				if(!mkey.isEmpty()){
					out.println("NO");
					return;
				}
			}
		}
		out.println("YES");
	}
	
	public void simulate(BitSet[] team, int[] posteam, Resident[] r, BitSet start, int k, int[][] link, int n, int[] ikeys, BitSet[] verkey)
	{
		ArrayDeque<Integer> q = new ArrayDeque<Integer>();
		for(int i = start.nextSetBit(0);i != -1;i = start.nextSetBit(i+1)){
			for(int j = verkey[i].nextSetBit(0);j != -1;j = verkey[i].nextSetBit(j+1)){
				q.add(j);
			}
		}
		
		Arrays.fill(posteam, -1);
		for(int i = 0;i < k;i++){
			team[r[i].pos].set(i);
			posteam[r[i].pos] = r[i].pos;
		}
		
		while(!q.isEmpty()){
			int cur = q.pollFirst();
			int v1 = link[cur][0];
			int v2 = link[cur][1];
			int t1 = posteam[v1];
			int t2 = posteam[v2];
			int has = posteam[r[ikeys[cur]].pos];
			if(t1 != has && t2 != has)continue;
			if(t1 >= 0 && t2 >= 0){
				if(t1 == t2)continue;
				// 
				team[t1].or(team[t2]);
				for(int i = 0;i < n;i++){
					if(posteam[i] == t1){
						// t1
						for(int j = verkey[i].nextSetBit(0);j != -1;j = verkey[i].nextSetBit(j+1)){
							q.add(j);
						}
					}else if(posteam[i] == t2){
						// t2
						for(int j = verkey[i].nextSetBit(0);j != -1;j = verkey[i].nextSetBit(j+1)){
							q.add(j);
						}
						posteam[i] = t1;
					}
				}
			}else if(t1 >= 0){
				for(int j = verkey[v2].nextSetBit(0);j != -1;j = verkey[v2].nextSetBit(j+1)){
					q.add(j);
				}
				posteam[v2] = t1;
			}else if(t2 >= 0){
				for(int j = verkey[v1].nextSetBit(0);j != -1;j = verkey[v1].nextSetBit(j+1)){
					q.add(j);
				}
				posteam[v1] = t2;
			}
		}
	}
	
	class Resident
	{
		public String name;
		public int pos;
		public int[] keys;
	}
	
	void run() throws Exception
	{
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
	void tr(Object... o) { System.err.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}