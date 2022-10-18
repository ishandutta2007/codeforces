import java.util.*
import kotlin.collections.HashMap
 
var scanner = Scanner(System.`in`)
 
fun readInt(): Int = scanner.nextInt()
fun readString(): String = scanner.next()

var a=IntArray(2005);
var b=IntArray(2005);
var c=IntArray(4005);

fun main()
{
	var T=readInt()
	for(iii in 1 .. T)
	{
		var n=readInt()
		for(i in 1 .. n)
		{
			a[i]=readInt()
			b[i]=readInt()
			c[2*i-1]=a[i]
			c[2*i]=b[i]
		}
		var ans=-1
		for(i in 1 .. n*2)
		{
			var x=c[i]
			var cnt=0
			for(j in 1 .. n)
			{
				if(a[j]<=x&&x<=b[j]) cnt++
			}
			if(cnt==1) ans=x
			x=c[i]+1
			cnt=0
			for(j in 1 .. n)
			{
				if(a[j]<=x&&x<=b[j]) cnt++
			}
			if(cnt==1) ans=x
		}
		print(ans)
		print("\n")
	}
}