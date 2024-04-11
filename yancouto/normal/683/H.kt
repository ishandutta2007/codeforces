import java.util.ArrayList
val seen = IntArray(112345)
val vec = IntArray(112345)

fun main(args : Array<String>) {
	//var (a, x, y) = readLine()!!.split(' ').map(String::toInt)
	for(i in 0..112344)
		seen[i] = 0
	val s = readLine()!!.split(' ')
	val n = s[0].toInt()
	val k = s[1].toLong()
	val a = readLine()!!.split(' ').map(String::toInt)
	for(i in 0..(n - 1)) {
		if(seen[i] == 1) continue
		val v = ArrayList<Int>()
		var j = i
		while(seen[j] == 0) {
			seen[j] = 1
			v.add(j)
			j = a[j] - 1
		}
		for(j in 0..(v.size - 1))
			vec[v[((j.toLong() + k) % v.size.toLong()).toInt()]] = v[j] + 1
	}
	for(i in 0..(n-1))
		print("${vec[i]} ")
	println("")
}