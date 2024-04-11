
import java.util.ArrayList;
import java.util.Scanner;
public class susbus {
	static ArrayList<Integer> knightone = new ArrayList<Integer>();
	static ArrayList<Integer> knighttwo = new ArrayList<Integer>();
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k1 = sc.nextInt();
		for(int i=0;i<k1;i++) {
			knightone.add(sc.nextInt());
//			System.out.print(knightone.get(i) + " ");
		}
//		System.out.println();
		int k2=sc.nextInt();
		for(int i=0;i<k2;i++) {
			knighttwo.add(sc.nextInt());
//			System.out.print(knighttwo.get(i) + " ");
		}
//		System.out.println();
		war(knightone,knighttwo);
	}
	static int fightCount =0;
	public static void war(ArrayList<Integer> knightone,ArrayList<Integer> knighttwo) {
		if(fightCount>200) {
			System.out.println(-1);
			return;
		}
		if(knighttwo.size() ==0) {
			System.out.println(fightCount);
			System.out.println(1);
			return;
		}
		if(knightone.size() == 0) {
			System.out.println(fightCount);
			System.out.println(2);
			return;
		}
		if(knightone.get(0)>knighttwo.get(0)) {
			knightone.add(knightone.size(),knighttwo.get(0));
			knightone.add(knightone.size(),knightone.get(0));
			knighttwo.remove(0);
			knightone.remove(0);
			fightCount++;
			war(knightone,knighttwo);
		}
		else {
			knighttwo.add(knighttwo.size(),knightone.get(0));
			knighttwo.add(knighttwo.size(),knighttwo.get(0));
			knighttwo.remove(0);
			knightone.remove(0);
			fightCount++;
			war(knightone,knighttwo);
		}
		
	}
}