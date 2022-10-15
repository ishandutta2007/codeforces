import java.io.*;
import java.util.*;

public class Main {
	static int maxC=(int)1e6, s;
	static List<Person> pplLeft = new ArrayList<Person>(), pplRight = new ArrayList<Person>();
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n=in.nextInt();
		s=in.nextInt();
		for(int i=0; i<n; ++i) {
			Person person = new Person(in.nextInt(), in.nextInt());
			if(in.nextInt()==1)
				pplLeft.add(person);
			else
				pplRight.add(person);
		}
		double l=0, r=maxC;
		while(r-l>1e-7) {
			double mid=(l+r)/2;
			if(can(mid))
				r=mid;
			else
				l=mid;
		}
		System.out.println(l);
	}
	
	static int[] deltaLeft = new int[maxC+1], deltaRight = new int[maxC+1];
	
	static boolean can(double t) {
		Arrays.fill(deltaLeft, 0);
		Arrays.fill(deltaRight,0);
		
		for(Person person : pplLeft) {
			if(person.loc<=t*person.vel) {
				++deltaLeft[0];
				break;
			}
			double x=person.loc, v=person.vel;
			double b=((s+v)*(s-v)*t+v*x)/s;
			if(b<person.loc)
				continue;
			++deltaLeft[person.loc];
			if(b<maxC)
				--deltaLeft[(int)b+1];
		}
		for(Person person : pplRight) {
			int dist=maxC-person.loc;
			if(dist<=t*person.vel) {
				++deltaRight[0];
				break;
			}
			double x=dist, v=person.vel;
			double b=maxC-(((s+v)*(s-v)*t+v*x)/s);
			if(b>person.loc)
				continue;
			++deltaRight[(int)Math.max(Math.ceil(b), 0)];
			if(person.loc<maxC)
				--deltaRight[person.loc+1];
		}
		int sumL=0, sumR=0;
		for(int i=0; i<=maxC; ++i) {
			sumL+=deltaLeft[i];
			sumR+=deltaRight[i];
			if(sumL>0&&sumR>0)
				return true;
		}
		
		return false;
	}
	
	static class Person {
		int loc, vel;
		Person(int loc, int vel) {
			this.loc=loc;
			this.vel=vel;
		}
	}
}