    /* package whatever; // don't place package name! */
     
    import java.util.*;
    import java.lang.*;
    import java.io.*;
     
    /* Name of the class has to be "Main" only if the class is public. */
    public class Ideone
    {
    	public static void main (String[] args) throws java.lang.Exception
    	{
    		// your code goes here
    		Scanner sc=new Scanner(System.in);
    		int n=sc.nextInt();
    		int[] a=new int[n];
    		for(int i=0;i<n;i++)a[i]=sc.nextInt();
    		int l=0,h=n,ans=-1;
    		while(l<=h){
    			int m=(l+h)/2;
    			if(check(a,m)){ans=m;h=m-1;}
    			else l=m+1;
    		}
    		System.out.println(ans);
    	}
    	public static boolean check(int[] a,int k){
    		// System.out.println(k+" k");
    		int l=0,h=k-1,n=a.length;
   			HashMap<Integer,Integer> map=new HashMap<>();
   			HashSet<Integer> set=new HashSet<>();
    		for(int i=h+1;i<n;i++)map.put(a[i],map.getOrDefault(a[i],0)+1);
    		for(Integer key:map.keySet())if(map.get(key)>1)set.add(key);
    		// System.out.println(map+" "+set);
    		if(k==0){if(set.size()==0)return true;else return false;}
    		if(set.size()==0)return true;
    		while(++h<n){
    			// System.out.println(l+" "+h);
    			map.put(a[h],map.get(a[h])-1);
    			// System.out.println(map+" mp");
    			map.put(a[l],map.getOrDefault(a[l],0)+1);
    			if(map.get(a[h])<=1)set.remove(a[h]);
    			if(map.get(a[l])>1)set.add(a[l]);
	    		// System.out.println(map+" "+set);
    			if(set.size()==0)return true;
    			l++;
    			
    		}
    		return false;
    	}
    }