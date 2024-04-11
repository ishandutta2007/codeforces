import java.util.ArrayList

val v :IntArray = IntArray(2000)



fun main(args : Array<String>) {
	//var (a, x, y) = readLine()!!.split(' ').map(String::toInt)
	for(i in 0..1500) {
		v[i] = 0
	}
	val n = readLine()!!.toInt()
	val a = readLine()!!.split(' ').map(String::toInt)
	for(j in 0..n-1) {
		var ct = 0
		for(i in 0..n-1) {
			if(v[i] == 0) ct++
			if(ct == a[j] + 1) {
				v[i] = j + 1
				break
			}
		}
	}
	for(i in 0..n-1)
		print("${v[i]} ")
	println("")
}