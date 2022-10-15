import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.util.TreeSet;


public class TwoTeams {
	
	static class Skill {
		 int index;
		 int skill;
		@Override
		public String toString() {
			return "Skill [index=" + index + ", skill=" + skill + "]";
		}
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int k = s.nextInt();
		TreeSet<Integer>  sk = new TreeSet<Integer>();
		List<Skill> ls = new ArrayList<>();
		
		for(int i=0;i<n;i++) {
			Skill skill = new Skill();
			skill.index =i;
			skill.skill = s.nextInt();
			ls.add(skill);
			sk.add(i);
		}
		
		int [] ar = new int[n];
		Comparator<Skill> com = new Comparator<TwoTeams.Skill>() {
			
			@Override
			public int compare(Skill o1, Skill o2) {
				
				return o2.skill-o1.skill;
			}
		};
		Collections.sort(ls, com);
		
		int team =1;
		
		for(int i=0;i<n;i++) {
//			System.out.println(sl);
			Skill sl = ls.get(i);
			
			Integer index = sl.index;
			if(ar[index]==0) {
				ar[index]=team;
				sk.remove(index);
				int tempK =k;
				
				while(tempK>0) {
					Integer stemp = sk.higher(sl.index);
					if(stemp==null)
						break;
					ar[stemp] = team;
					tempK--;
					sk.remove(stemp);
				}
				
				tempK =k;
				while(tempK>0) {
					Integer stemp = sk.lower(sl.index);
					if(stemp==null)
						break;
					ar[stemp] = team;
					tempK--;
					sk.remove(stemp);
				}
				
				team++;
				if(team>2)
					team-=2;
			}
			
		}
		
		for(int i=0;i<n;i++) {
			System.out.print(ar[i]);
		}
		System.out.println("");


	}

}