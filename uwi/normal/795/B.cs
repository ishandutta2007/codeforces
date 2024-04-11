using System;
using System.Linq;
using System.Collections.Generic;

public static class Program
{
	class Cup {
	  public int s;
	  public int w;
	
	  public Cup(int s, int w)
	  {
	    this.s = s;
	    this.w = w;
	  }
	}	
	
  static int Compare(Cup x, Cup y)
  {
    if (x.s != y.s){
      return x.s > y.s ? -1 : 1;
    }else if (x.w != y.w){
      return x.w < y.w ? -1 : 1;
    }else{
      return 0;
    }
  }	
  
    public static void Main()
    {
        var nmd = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var n = nmd[0];
        var m = nmd[1];
        var d = nmd[2];

		List<Cup> la = new List<Cup>();
        for(int i = 0;i < n;i++){
    		var sw = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        	la.Add(new Cup(sw[0], sw[1]));
        }
		List<Cup> lb = new List<Cup>();
        for(int i = 0;i < m;i++){
    		var sw = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        	lb.Add(new Cup(sw[0], sw[1]));
        }
        la.Sort(Compare);
        lb.Sort(Compare);
        int p = 0;
        int q = lb.Count()-1;
        long ssum = 0;
        long wsum = 0;
        for(int i = 0;i < m;i++){
        	ssum += lb[i].s;
        	wsum += lb[i].w;
        }
        long ret = 0;
        for(int i = 0;i < n;i++){
        	ssum += la[i].s;
        	wsum += la[i].w;
        	while(wsum > d && q >= 0){
        		ssum -= lb[q].s;
        		wsum -= lb[q].w;
				q--;
        	}
        	if(wsum <= d && q >= 0){
        		ret = Math.Max(ret, ssum);
        	}
        }
        Console.WriteLine(ret);
    }
}