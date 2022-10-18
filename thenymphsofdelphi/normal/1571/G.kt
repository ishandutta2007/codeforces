import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

class SegmentTree{
    private val segmax: LongArray
    private val len: Int
 
    constructor(size: Int) {
        segmax = LongArray(size * 4) { -1000000000000000000L }
        len = size
    }
    fun update(ind: Int = 1, value: Long, segLeft: Int = 1, segRight: Int = len, left: Int, right: Int) {
        if (segLeft > right || segRight < left || segLeft > segRight) {
            return
        }
        if (left <= segLeft && segRight <= right) {
            segmax[ind] = max(segmax[ind], value)
            return
        } else {
            val mid = (segLeft + segRight) / 2
            update(ind * 2, value, segLeft, mid, left, right)
            update(ind * 2 + 1, value, mid + 1, segRight, left, right)
            segmax[ind] = max(segmax[ind * 2], segmax[ind * 2 + 1])
        }
    }
 
    fun getmax(ind: Int = 1, segLeft: Int = 1, segRight: Int = len, left: Int, right: Int): Long {
        if (segLeft > right || segRight < left || segLeft > segRight) {
            return -1000000000000000000L
        }
        if (left <= segLeft && segRight <= right) {
            return segmax[ind]
        }
        val mid = (segLeft + segRight) / 2
        val leftValue = getmax(ind * 2, segLeft, mid, left, right)
        val rightValue = getmax(ind * 2 + 1, mid + 1, segRight, left, right)
        return max(leftValue, rightValue)
    }
}

fun main(){
    val (n, m) = readLongs()
    val cc = mutableListOf <Triple <Long, Long, Long>>()
    cc.add(Triple <Long, Long, Long>(0L + m, -m - 1L, 0L))
    for (i in 1..n){
        val k = readInt()
        val a = readLongs()
        val b = readLongs()
        for (j in 0..k-1){
            cc.add(Triple(i + b[j], -b[j] - 1, a[j]))
        }
    }
    val c = cc.sortedWith(compareBy({ it.first }, { it.second }, { it.third }))
    val seg = SegmentTree(m.toInt() + 2)
    var ans = 0L
    val aans = LongArray(c.size)
    var li = 0
    for (ri in 1..c.size){
        if (ri == c.size || c[ri].first != c[ri - 1].first){
            for (i in li..ri-1){
                aans[i] = c[i].third + seg.getmax(1, 1, m.toInt() + 2, -c[i].second.toInt(), m.toInt() + 2)
                ans = max(ans, aans[i])
            }
            for (i in li..ri-1){
                if (c[i].first == m && c[i].second == -m - 1){
                    seg.update(1, 0, 1, m.toInt() + 2, -c[i].second.toInt(), -c[i].second.toInt())
                    continue
                }
                seg.update(1, aans[i], 1, m.toInt() + 2, -c[i].second.toInt(), -c[i].second.toInt())
            }
            li = ri
        }
    }
    println(ans)
}