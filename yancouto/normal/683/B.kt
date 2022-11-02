import java.util.ArrayList
val g : Array<ArrayList<String>> = Array(500, {i -> ArrayList<String>()})

fun main(args : Array<String>) {
	var (n) = readLine()!!.split(' ').map(String::toInt)
	for(i in 1..n) {
		val x = readLine()!!.split(' ')
		g[x[1].toInt()].add(x[0])
	}
	for(i in 1..400)
		for(s in g[i])
			println(s)
}