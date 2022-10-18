import java.util.*
import kotlin.collections.HashMap
 
var scanner = Scanner(System.`in`)
 
fun readInt(): Int = scanner.nextInt()
fun readString(): String = scanner.next()

fun main()
{
	var T=readInt()
	for(i in 1 .. T)
	{
		var x=readInt();
		if(x<=999)
		{
			print(x)
			print("\n")
		}
		else if(x<=999499)
		{
			print((x+500)/1000)
			print("K\n")
		}
		else
		{
			print((x+500000)/1000000)
			print("M\n")
		}
	}
}