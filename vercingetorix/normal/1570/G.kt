fun ask(a:List<Int>) : Int {
    print("? ")
    println(a.joinToString(" "))
    System.out.flush()
    return read()
}

fun main() {
    val d7 = 1.shl(7)
    var a = List(100) {it+1}
    var b = List(100) {it.shl(7)}
    val ans = (ask(b).and(d7-1) + ask(a).and(d7*d7-d7))
    println("! $ans")
}

private fun read() = readLine()!!.toInt()
private fun readv() = readLine()!!.split(" ").map {it.toInt()}