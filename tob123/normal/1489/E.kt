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

fun main(){
	val nn = 2e5.toInt() + 10
	val T = readInt()
    var dp = IntArray(T+1) {0}
	var idTime = IntArray(nn) {0}
	var start = IntArray(nn)
    var cnt = 0
	for (i in 1..T){
		val (t, ids) = readStrings()
		val id = ids.toInt()
		dp[i] += dp[i-1]
        when(t){
        	"L" -> {
				cnt++
				dp[i]++
				start[id] = 1
				idTime[id] = i
        	}
			"R" -> {
				cnt++
				start[id] = cnt
				idTime[id] = i
			}
            "?" -> {
				val ind = start[id] + dp[i] - dp[idTime[id]]
				val res = minOf(ind-1, cnt-ind)
				println(res)
            }
		}
		/*
		printColl(dp.toList())
		printColl(idTime.toList())
		printColl(start.toList())
		 */
	}
}