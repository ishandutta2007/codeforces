import java.util.ArrayList

val a1 :IntArray = IntArray(4000)
val a2 :IntArray = IntArray(4000)


fun go(a : IntArray) {
	val x = readLine()!!.split(' ').map(String::toInt)
	for(i in 1..(x.size-1))
		a[x[i] + 1010] = 1
}

fun main(args : Array<String>) {
	//var (a, x, y) = readLine()!!.split(' ').map(String::toInt)
	for(i in 0..3000) {
		a1[i] = 0
		a2[i] = 0
	}
	go(a1)
	go(a2)
	val v = ArrayList<Int>()
	for(i in 0..3000)
		if((a1[i] == 1 && a2[i] == 0) || (a1[i] == 0 && a2[i] == 1))
			v.add(i - 1010)
	print("${v.size}")
	for(i in v)
		print(" $i")
	println("")
}