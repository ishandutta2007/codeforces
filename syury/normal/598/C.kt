import java.util.*
import kotlin.system.exitProcess
import kotlin.math.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun exit() : Nothing = exitProcess(0)

inline fun <T : Comparable<T> > min(x : T, y : T): T{
    if(x < y){return x;}
    else{return y;}
}

inline fun <T : Comparable<T> > max(x : T, y : T): T{
    if(x > y){return x;}
    else{return y;}
}

data class Point (val x: Long, val y : Long, val idx : Int){}

fun half(a : Point): Int{
    if((a.y > 0L)or(a.y == 0L && a.x > 0L)){return 0;}
    else{return 1;}
}

fun sgn(a : Long): Int{
    if(a < 0L){return -1;}
    if(a == 0L){return 0;}
    return 1;
}

class ComparePoints{
    companion object : Comparator<Point> {
        override fun compare(a: Point, b: Point): Int = when {
            half(a) != half(b) -> half(a) - half(b)
            else -> sgn(a.x * b.y - b.x * a.y)
        }
    }
}

fun cross(a : Point, b : Point): Long{
    return a.x * b.y - b.x * a.y;
}

fun main(){
    val n = readInt();
    var a = ArrayList<Point>();
    for(i in 0..n-1){
        val (x, y) = readLongs();
        a.add(Point(x, y, i));
    }
    val b = a.sortedWith(ComparePoints);
    var a1 = -1;
    var a2 = 0;
    var zalupa = Point(-1, -1, -1);
    for(i in 0..n-1){
        var j = i + 1;
        if(j == n){j = 0;}
        val bishkek = Point(b[i].x * b[j].x + b[i].y * b[j].y, abs(b[i].x * b[j].y - b[i].y * b[j].x), -1);
        if((-1 == a1)or(cross(bishkek, zalupa) > 0)){
            zalupa = bishkek;
            a2 = b[i].idx + 1;
            a1 = b[j].idx + 1;
        }
    }
    println(a1.toString() + " " + a2.toString());
}