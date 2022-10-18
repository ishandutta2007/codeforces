import java.util.*
import kotlin.collections.HashMap
 
var scanner = Scanner(System.`in`)
 
fun readInt() = scanner.nextInt()
fun readInts() = readLine()!!.split(" ").map { it.toInt() }

var a=IntArray(100005);

fun main()
{
	var T=readInt()
	for(iii in 1 .. T)
	{
		var n=readInt()
		var sum=0;
		for(i in 1 .. n)
		{
			a[i]=readInt()
			if(a[i]>0) sum+=a[i];
		}
		var minid=0;
		var minn=100000;
		for(i in 1 .. n)
		{
			if(a[i]>0)
			{
				if(a[i]<minn)
				{
			    	minn=a[i];
			    	minid=i;
			    }
			}
			if(a[i]<0)
			{
				if(-a[i]<minn)
				{
				    minn=-a[i];
				    minid=i;
				}
			}
		}
		if(a[minid]>0)
		{
			println(sum-minn);
			for(i in 1..n)
			{
				if(a[i]>0)
				{
					if(i==minid) print("0");
					else print("1");
				}
				else print("0");
			}
			print("\n");
		}
		else
		{
			println(sum-minn);
			for(i in 1..n)
			{
				if(a[i]<=0)
				{
					if(i==minid) print("1");
					else print("0");
				}
				else print("1");
			}
			print("\n");
		}
	}
}