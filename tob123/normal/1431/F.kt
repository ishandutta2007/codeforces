import java.util.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun <T>printColl(a : Collection<T>){
	for(x in a)
		print("$x ")
	println()
}

/*
toIntArray()
IntArray(sz) {initVal}
ArrayList<T>(...)
IntArrayOf(a, b, c)
minOf(x, y)
1 shl 10
println(res.joinToString(" "))
a.map {it.toString()}
l.toIntArray()
*/

val INF : Long = (1e12).toLong()
var A = listOf(0L)
var N = 0
var K = 0
var X = 0

fun calcRes(cost : Long) : Long{
	//println("called with $cost")
	var stI = 0
    var res = 0L
    while(stI < A.size){
		var sum = 0L
		val PQ = PriorityQueue<Long>()
		for(i in 0 until Math.min(X, A.size-stI)){
			sum += A[i+stI]
			PQ.add(-A[i+stI])
			//println("add ${A[i+stI]}")
		}
		stI += X
		while(sum > cost){
			res++
			//println("rem ${PQ.peek()}")
			sum += PQ.poll()!!
			if(stI < A.size){
				//println("add ${A[stI]}")
				PQ.add(-A[stI])
                sum += A[stI]
				stI++
			}
		}
		//println("$stI -> $res")
	}
	//println("$cost $res")
    return res
}

fun main(){
	val T = 1
	for (t in 1..T){
		val (n, k, x) = readInts()
        N = n
		K = k
		X = x
		A = readLongs()
		/*
        if(N-K <= X){
			var B = A.toLongArray()
			B.sort()
			var sum = 0L
			for(i in 0 until N-K)
				sum += B[i]
			println(sum)
			continue
		}
		 */
        var lo = 0L
		var hi = INF
		while(lo < hi){
			val m = (lo+hi)/2
			val ret = calcRes(m)
            if(ret <= K){
				hi = m
			}
			else
				lo = m+1
		}
		println(lo)
	}
}