import java.util.*

fun min(x: Int, y: Int, z: Int): Int{
    var ans = x;
    if(ans > y){ans = y;}
    if(ans > z){ans = z;}
    return ans;
}

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val (y, b, r) = readInts();
    var ans = min(y, b - 1, r - 2);
    println(3 * ans + 3);
}