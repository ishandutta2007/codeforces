fun removeZeros(x: Int): Int =
    if (x % 10 == 0) removeZeros(x / 10); else x
fun f(x: Int) = removeZeros(x + 1);
fun main() {
    var n = readLine()!!.toInt();
    val reached = HashSet<Int>();
    while(reached.add(n)) n = f(n);
    println(reached.size);
}