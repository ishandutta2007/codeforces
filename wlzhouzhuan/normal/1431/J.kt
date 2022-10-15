import java.io.*
import java.util.*
import kotlin.system.exitProcess

// @JvmField val INPUT = File("input.txt").inputStream()
// @JvmField val OUTPUT = File("output.txt").outputStream()

/// https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.jvm/-jvm-field/

class Kattio: PrintWriter {
    @JvmField val r: BufferedReader
    @JvmField var st = StringTokenizer("")
    constructor(): this(System.`in`,System.out) {}
    constructor(i: InputStream, o: OutputStream): super(o,false) { r = i.bufferedReader() }
    fun rLine(): String? = r.readLine()

    fun read(): String { // if no input left returns empty string
        while (st.hasMoreTokens().not()) st =
            StringTokenizer(rLine() ?: return "", " ")
        return st.nextToken()
    }
    fun strs(n: Int) = List(n){read()}
    fun ln() = rLine()!!
    fun lns(n: Int) = List(n){ln()}
    fun int() = read().toInt()
    fun ints(n: Int) = List(n){int()}
    fun db() = read().toDouble()
    fun rDbs(n: Int) = List(n){db()}
    fun long() = read().toLong()
    fun longs(n: Int) = List(n){long()}
}

val io = Kattio()
//const val MOD = 1000000007
const val MOD = 998244353
const val INF = (1e18).toLong()
const val SZ = 1 shl 17

fun YN(b: Boolean) : String { return if (b) "YES" else "NO"  }
fun add(a: Int, b: Int) = (a+b) % MOD // from tourist :o
fun sub(a: Int, b: Int) = (a-b+MOD) % MOD
fun mul(a: Int, b: Int) = ((a.toLong()*b)%MOD).toInt()
fun gcd(a: Int, b: Int) : Int = if (b == 0) a else gcd(b,a%b)

fun example() {
    println(String.format("%.8f", 5.25)) // print to 8 decimals
    val arr2D = Array<IntArray>(5,{IntArray(5,{5})})
    var (x,y) = arrayOf(3,2) // or rInts(2)
    when (x) { //  switch, can be used as expression
        0,1 -> println("x <= 1")
        2 -> println("x == 2") // Note the block
        else -> { println("x is neither 1 nor 2") }
    }
    x = y.also { y = x } // swap x and y
    println("${maxOf(x+2,y)}") // (x,y)=(4,3) -> 4
    val h = HashMap<String,Int>()
    val s = "ababa"
    for (i in 0..s.length-2) {
        val w = s.substring(i,i+2)
        val c = h.getOrElse(w,{0})
        h[w] = c+1
    }
    for ((a,b) in h) println("${a} ${b}") // key,value
    val pq = PriorityQueue<Pair<Long,Int>>(){x,y ->
        x.first.compareTo(y.first)} // or compareBy{it.first}
    val A = arrayListOf(Pair(1,3),Pair(3,2),Pair(2,3))
    val B = A.sortedWith(Comparator<Pair<Int,Int>>{x,y ->
        x.first.compareTo(y.first)}) // or sortBy{it.first}
    val list = arrayListOf('a','b','c','d','e')
    println(list.binarySearch('d')) // 3
    list.remove('d')
    val actualInsertPoint = -(list.binarySearch('d')+1) // 3
    list.add(actualInsertPoint, 'd') // [a,b,c,d,e]
    list.removeAt(1) // remove at index -> [a,c,d,e]
}

fun solve() {
    fun divi(po: Int, lo: Long, hi: Long, l: Long, r: Long, res: ArrayList<Pair<Int,Long>>) {
        if (hi < l || r < lo) return
        if (l <= lo && hi <= r) {
            res.add(Pair<Int,Long>(po,lo))
            return
        }
        val mid = (lo+hi)/2
        divi(po-1,lo,mid,l,r,res)
        divi(po-1,mid+1,hi,l,r,res)
    }
    fun getRanges(l: Long, r: Long): ArrayList<Pair<Int,Long>> {
        val res = ArrayList<Pair<Int,Long>>()
        divi(60,0L,(1L shl 60)-1,l,r,res)
        return res
    }
    val n = io.int()
    val a = io.longs(n)
    var des = 0L
    for (i in a) des = des xor i

    var tmp = Array<HashMap<Long,Int>>(61){HashMap<Long,Int>()}
    var tmp2 = Array<HashMap<Long,Int>>(61){HashMap<Long,Int>()}
    tmp[0][des] = 1
    tmp2[0][0] = 1

    fun addRanges(tmp: Array<HashMap<Long,Int>>, ranges: ArrayList<Pair<Int,Long>>) {
//        println(ranges)
        val TMP = Array<HashMap<Long,Int>>(61){HashMap<Long,Int>()}
        for (i in 0..60) for ((key,value) in tmp[i]) {
            for (range in ranges) {
                val I = maxOf(range.first,i)
                var KEY = key xor range.second
                KEY = KEY xor (KEY and ((1L shl I)-1))
                val VALUE = mul(value,((1L shl minOf(range.first,i))%MOD).toInt())
                TMP[I][KEY] = add(TMP[I].getOrDefault(KEY,0),VALUE)
            }
        }
//        tmp = TMP
        for (i in 0..60) {
            tmp[i] = TMP[i]
        }
//        fo
//        for (i in 0..10) {
//            println(i)
//            println(tmp[i])
//        }
    }

    for (i in 0..n-2) { // 0 to 15
//        println("WHOOPS ${i}")
        if (i <= n/2-1) addRanges(tmp,getRanges(a[i],a[i+1]))
        else addRanges(tmp2,getRanges(a[i],a[i+1]))
    }
    var ans = 0
    for (i in 0..60) for (j in i..60)  {
//        println("DOING ${i} ${j}")
        for ((key,value) in tmp[i]) {
            val key2 = key xor (key and ((1L shl j)-1))
            if (key2 in tmp2[j]) {
                val value2 = tmp2[j][key2]!!
                ans = add(ans, mul(mul(value, value2), ((1L shl i) % MOD).toInt()))
            }
        }
    }
    for (j in 0..60) for (i in j+1..60)  {
//        println("DOING ${i} ${j}")
        for ((key2,value2) in tmp2[j]) {
            val key = key2 xor (key2 and ((1L shl i)-1))
            if (key in tmp[i]) {
                val value = tmp[i][key]!!
                ans = add(ans,mul(mul(value,value2),((1L shl j)%MOD).toInt()))
            }
        }
    }
    println(ans)
}

fun main() {
//    val t = io.int()
    val t = 1
    repeat(t) { solve() }
    io.close()
}