import java.io.*

val MOD = 1000000007
val SZ = 1 shl 18
val INF = (1e18).toLong()
 
fun add(a: Int, b: Int) = (a + b) % MOD // from tourist :o
fun sub(a: Int, b: Int) = (a - b + MOD) % MOD
fun mul(a: Int, b: Int) = ((a.toLong() * b) % MOD).toInt()
fun min(a: Double, b: Double) = if (a < b) a else b
fun max(a: Double, b: Double) = if (a > b) a else b
fun min(a: Long, b: Long) = if (a < b) a else b
fun min(a: Int, b: Int) = if (a < b) a else b
fun max(a: Long, b: Long) = if (a > b) a else b
 
private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun printInts(a: Array<Int>) = println(a.joinToString("\n")) 
private fun bufferOut(block: PrintWriter.() -> Unit) = PrintWriter(System.out).use { block(it) }

fun gcd(a: Int, b: Int): Int {
    return if (a == 0) b else gcd(b % a,a)
}

var zero = 0.toLong();
var one = 1.toLong();
var two = 2.toLong();
var three = 3.toLong();
var four = 4.toLong();
var five = 5.toLong();
fun powmod(aa: Long, bb: Long, mod: Long): Long {
    var ret = one
    var a = aa
    var b = bb
    while (b > zero) {
        if (b % two == one) {
            ret = ret * a % mod
        }
        a = a * a % mod
        b = b / 2
    }
    return ret
}

fun main(args: Array<String>) = bufferOut { readSolveWrite() }

val max2 = 29
val max3 = 18
val max5 = 12
val max7 = 10
val LIM: Long = 1001000000
val C = Array(100, {LongArray(100)})
val f = Array(34, {Array(34, {LongArray(34, {0})})})

// f[c2][c3][len - c5 - c7] * calc(len-c5-c7, c5, c7)

private fun gao(xx : Int, y : Int): Long {
    var x = xx
    if (x >= 0 && y >= 0 && y >= x) {
        if (x <= 99 && y <= 99)
            return min(LIM, C[y][x]);
        else {
            x = min(x, y - x)
            if (x == 0) return one
            if (x == 1) return y.toLong()
            var z = y.toLong()
            if (x == 2) {
                if (y >= 100000) return LIM
                else return min(LIM, z * (z - 1) / 2);
            } 
            if (x == 3) {
                if (y >= 10000) return LIM
                else return min(LIM, z * (z - 1) * (z - 2) / 6);
            } 
            if (x == 4) {
                if (y >= 1000) return LIM
                else return min(LIM, z * (z - 1) * (z - 2) * (z - 3) / 24);
            } 
            if (x == 5) {
                if (y >= 1000) return LIM
                else return min(LIM, z * (z - 1) * (z - 2) * (z - 3) * (z - 4) / 120);
            } 
            return LIM
        }
    }
    else {
        return zero;
    }
}

private fun calc(c2 : Int, c3 : Int, c5 : Int, c7 : Int, len : Int): Long {
    // print(c2)
    // print(" ")
    // print(c3)
    // print(" ")
    // print(c5)
    // print(" ")
    // print(c7)
    // print(" ")
    // print(len)
    // print(" ")
    if (c2 + c3 + c5 + c7 == 1 && c2 >= 0 && c3 >=0 && c5 >=0 && c7 >= 0) {
        return len.toLong()
    }
    if (c2 + c3 + c5 + c7 == 0 && c2 >= 0 && c3 >=0 && c5 >=0 && c7 >= 0) {
        return one
    }
    var ans: Long = 0
    for (i in 0..len) {
        var ll = len
        var ret = gao(i, ll)
        ll -= i
        ret = min(LIM, ret * gao(c5, ll))
        ll -= c5
        ret = min(LIM, ret * gao(c7, ll))
        ll -= c7
        if (ll >= 0 && c2 >= 0 && c3 >= 0 && ll < 34)
            ret = ret * f[c2][c3][ll]
        else
            ret = 0;
        ans = min(LIM, ans + ret);
    }
    // println(ans)
    return ans
}

private fun PrintWriter.readSolveWrite() {
    // val pw2 = Array<Long>(max2 + 1, {powmod(2, it, LIM)})
    // val pw3 = Array<Long>(max3 + 1, {powmod(3, it, LIM)})
    // val pw5 = Array<Long>(max5 + 1, {powmod(5, it, LIM)})
    // val pw7 = Array<Long>(max7 + 1, {powmod(7, it, LIM)})
    // f[i][j][k] -> 2->i 3->j len->k
    C[0][0] = 1
    C[1][0] = 1
    C[1][1] = 1
    for (i in 2..99) {
        C[i][0] = 1
        C[i][i] = 1
        for (j in 1..i-1) {
            C[i][j] = min(LIM, C[i-1][j] + C[i-1][j-1])
        }
    }
    f[0][0][0] = 1;
    for (l in 1..30) {
        for (i in 0..33) {
            for (j in 0..33) {
                if (i >= 1) f[i][j][l] += f[i-1][j][l-1];
                if (i >= 2) f[i][j][l] += f[i-2][j][l-1];
                if (i >= 3) f[i][j][l] += f[i-3][j][l-1];
                if (j >= 1) f[i][j][l] += f[i][j-1][l-1];
                if (j >= 2) f[i][j][l] += f[i][j-2][l-1];
                if (i >= 1 && j >= 1) f[i][j][l] += f[i-1][j-1][l-1];
                f[i][j][l] = min(LIM, f[i][j][l])
            }
        }
    }
    var (m, k) = readInts()
    var K: Long = k.toLong()
    var c2 = 0
    var c3 = 0
    var c5 = 0
    var c7 = 0
    while (m % 2 == 0) {
        m /= 2;
        c2++;
    }
    while (m % 3 == 0) {
        m /= 3;
        c3++;
    }
    while (m % 5 == 0) {
        m /= 5;
        c5++;
    }
    while (m % 7 == 0) {
        m /= 7;
        c7++;
    }
    if (m != 1) {
        println("-1")
        return 
    }
    var len = c5 + c7
    var len_cnt = calc(c2, c3, c5, c7, len);
    while (len_cnt < K) {
        K -= len_cnt;
        len += 1;
        len_cnt = calc(c2, c3, c5, c7, len);
        // print("????")
        // println(K)
    }
    for (i in 1..len) {
        // print("????")
        // print(i)
        // print("????")
        // println(K)
        var tmp = calc(c2, c3, c5, c7, len - i);
        if (tmp >= K) {
            print("1")
            continue;
        }
        K -= tmp
        tmp = calc(c2 - 1, c3, c5, c7, len - i);
        if (tmp >= K) {
            c2 -= 1
            print("2")
            continue;
        }
        K -= tmp
        tmp = calc(c2, c3 - 1, c5, c7, len - i);
        if (tmp >= K) {
            c3 -= 1
            print("3")
            continue;
        }
        K -= tmp
        tmp = calc(c2 - 2, c3, c5, c7, len - i);
        if (tmp >= K) {
            c2 -= 2
            print("4")
            continue;
        }
        K -= tmp
        tmp = calc(c2, c3, c5 - 1, c7, len - i);
        if (tmp >= K) {
            c5 -= 1
            print("5")
            continue;
        }
        K -= tmp
        tmp = calc(c2 - 1, c3 - 1, c5, c7, len - i);
        if (tmp >= K) {
            c3 -= 1
            c2 -= 1
            print("6")
            continue;
        }
        K -= tmp
        tmp = calc(c2, c3, c5, c7 - 1, len - i);
        if (tmp >= K) {
            c7 -= 1
            print("7")
            continue;
        }
        K -= tmp
        tmp = calc(c2 - 3, c3, c5, c7, len - i);
        if (tmp >= K) {
            c2 -= 3
            print("8")
            continue;
        }
        K -= tmp
        tmp = calc(c2, c3 - 2, c5, c7, len - i);
        if (tmp >= K) {
            c3 -= 2
            print("9")
            continue;
        }
    }
    // var u = powmod(2, c2.toLong(), LIM) * powmod(3, c3.toLong(), LIM) * powmod(5, c5.toLong(), LIM) * powmod(7, c7.toLong(), LIM);
    println("")
}
 
class Evt(val i: Int, val p: Int, val d: Int)
 
private fun solveEvents(n: Int, es: ArrayList<Evt>): IntArray? {
    es.sortWith(Comparator { e1, e2 ->
        when {
            e1.p < e2.p -> -1
            e1.p > e2.p -> 1
            else -> e2.d - e1.d
        }
    })
    var cnt = 0
    val r = IntArray(n)
    var cur = 1
    var cc = 0
    for (e in es) {
        cnt += e.d
        when {
            e.d == 1 -> {
                r[e.i] = cur
                cc++
            }
            cnt == 0 && cur == 1 -> {
                cur = 2
                cc = 0
            }
        }
    }
    return if (cc == 0) null else r
}

/**
 * Description: Kotlin tips for dummies
 * Source: own
 */
 
/* sorting
 * 1 (ok)
    val a = nextLongs().sorted() // a is mutable list
 * 2 (ok)
    val a = arrayListOf<Long>() // or ArrayList<Long>()
    a.addAll(nextLongs())
    a.sort()
 *.3 (ok)
    val A = nextLongs()
    val a = Array<Long>(n,{0})
    for (i in 0..n-1) a[i] = A[i]
    a.sort()
 * 4 (ok)
    val a = ArrayList(nextLongs())
    a.sort()
 * 5 (NOT ok)
    val a = LongArray(N) // or nextLongs().toLongArray()
    Arrays.sort(a)
 */
/* 2D array
 * val ori = Array(n, {IntArray(n)})
 * val ori = arrayOf(
    intArrayOf(8, 9, 1, 13),
    intArrayOf(3, 12, 7, 5),
    intArrayOf(0, 2, 4, 11),
    intArrayOf(6, 10, 15, 14)
    )
 */
/* printing variables:
 * println("${l+1} and $r")
 * print d to 8 decimal places: String.format("%.8g%n", d)
 * try to print one stringbuilder instead of multiple prints
 */
/* comparing pairs
    val pq = PriorityQueue<Pair<Long,Int>>({x,y -> x.first.compareTo(y.first)})
    val pq = PriorityQueue<Pair<Long,Int>>(compareBy {it.first})
    val A = arrayListOf(Pair(1,3),Pair(3,2),Pair(2,3))
    val B = A.sortedWith(Comparator<Pair<Int,Int>>{x,y -> x.first.compareTo(y.first)})
    sortBy
 */
/* hashmap
    val h = HashMap<String,Int>()
    for (i in 0..n-2) {
        val w = s.substring(i,i+2)
        val c = h.getOrElse(w){0}
        h.put(w,c+1)
    }
 */
/* basically switch, can be used as expression
    when (x) {
        0,1 -> print("x <= 1")
        2 -> print("x == 2")
        else -> { // Note the block
            print("x is neither 1 nor 2")
        }
    }
*/
// swap : a = b.also { b = a }
// arraylist remove element at index: removeAt, not remove ...
// lower bound: use .binarySearch()
 
// fun next() = readLine()!!
// fun nextInt() = next().toInt()
// fun nextLong() = next().toLong()
// fun nextInts() = next().split(" ").map { it.toInt() }
// fun nextLongs() = next().split(" ").map { it.toLong() }