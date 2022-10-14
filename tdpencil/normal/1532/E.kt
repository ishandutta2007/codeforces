import java.util.*

fun main() {
    val T = 1
    repeat(T) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(" ").map({ it.toLong() })
        var count = IntArray(1000001)
        var tm = TreeSet<Long>()
        var s = 0L
        var ans = 0L
        for(i in 0 until n)
            tm.add(a[i])

        for(i in 0 until n) {
            s += a[i]
            count[a[i].toInt()]++
        }
        var ad = ArrayDeque<Int>()
        for(i in 0 until n) {
            val left = s - a[i]
            if(left % 2 == 0L && ((tm.contains(left / 2) && a[i] != left / 2) || (a[i] == left / 2 && count[a[i].toInt()] > 1)) )
                ad.add(i.toInt()+1)
        }
        println(ad.size)
        for(i in 0 until ad.size) {
            print(ad.remove())
            print(" ")
        }
    }
}