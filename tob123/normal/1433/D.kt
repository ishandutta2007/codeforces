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

val C = IntArray(6000)

fun find(x : Int) : Int {
	if(C[x] != x)
		C[x] = find(C[x])
	return C[x]
}

fun join(a:Int, b:Int){
	C[find(a)] = find(b)
}

fun main(){
	val T = readInt()
	for (t in 1..T){
		val n = readInt()
        val A = readInts()
		for(i in 0 until n)
			C[i] = i
		var res = ArrayList<Pair<Int,Int>>()
		for(i in 0 until n){
			for(j in 0 until n){
				if(i == j)
					continue
				if(A[i] != A[j] && find(i) != find(j)){
					join(i, j)
					res.add(Pair(i+1, j+1))
				}
			}
		}
		if(res.size == n-1){
			println("YES")
			print((res.map {"${it.first} ${it.second}\n"}).joinToString(""))
		}
		else
			println("NO")
	}
}