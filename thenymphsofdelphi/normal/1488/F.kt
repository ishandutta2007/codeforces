import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

class SegmentTree{

    private val segsum: LongArray
    private val segmin: IntArray
    private val lazy: IntArray
    private val len: Int

    /**
     * Creates an empty segment tree
     *
     * @param size Size of relevant range
     */
    constructor(size: Int) {
        segsum = LongArray(size * 4)
        segmin = IntArray(size * 4)
        lazy = IntArray(size * 4)
        len = size
    }

    /**
     * Updates the segment tree. Updates the nodes for a given range with a new value.
     *
     * @param ind Current index / node to update in the tree
     * @param value Adding this value to a given range
     * @param segLeft Left end of current segment
     * @param segRight Right end of current segment
     * @param left Left end of the update range
     * @param right Right end of the update range
     */
    fun update(ind: Int = 1, value: Int, segLeft: Int = 1, segRight: Int = len, left: Int, right: Int) {
        if (segLeft > right || segRight < left || segLeft > segRight) {
            return
        }
        if (left <= segLeft && segRight <= right) {
            segsum[ind] = value.toLong() * (segRight - segLeft + 1)
            segmin[ind] = value
            lazy[ind] = value
            return
        } else {
            propagateToChildren(ind, segLeft, segRight)
            val mid = (segLeft + segRight) / 2
            update(ind * 2, value, segLeft, mid, left, right)
            update(ind * 2 + 1, value, mid + 1, segRight, left, right)
            segsum[ind] = segsum[ind * 2] + segsum[ind * 2 + 1]
            segmin[ind] = min(segmin[ind * 2], segmin[ind * 2 + 1])
        }
    }

    /**
     * Get the sum of a given range in the tree.
     *
     * @param ind Current index / node of the segment tree
     * @param segLeft Left end of current segment
     * @param segRight Right end of current segment
     * @param left Left end of the query range
     * @param right Right end of the query range
     * @return sum of the range
     */
    fun getsum(ind: Int = 1, segLeft: Int = 1, segRight: Int = len, left: Int, right: Int): Long {
        if (segLeft > right || segRight < left || segLeft > segRight) {
            return 0
        }
        if (left <= segLeft && segRight <= right) {
            return segsum[ind]
        }
        propagateToChildren(ind, segLeft, segRight)
        val mid = (segLeft + segRight) / 2
        val leftValue = getsum(ind * 2, segLeft, mid, left, right)
        val rightValue = getsum(ind * 2 + 1, mid + 1, segRight, left, right)
        return leftValue + rightValue
    }

    /**
     * Get the sum of a given range in the tree.
     *
     * @param ind Current index / node of the segment tree
     * @param segLeft Left end of current segment
     * @param segRight Right end of current segment
     * @param left Left end of the query range
     * @param right Right end of the query range
     * @return sum of the range
     */
    fun getmin(ind: Int = 1, segLeft: Int = 1, segRight: Int = len, left: Int, right: Int): Int {
        if (segLeft > right || segRight < left || segLeft > segRight) {
            return 1000000007
        }
        if (left <= segLeft && segRight <= right) {
            return segmin[ind]
        }
        propagateToChildren(ind, segLeft, segRight)
        val mid = (segLeft + segRight) / 2
        val leftValue = getmin(ind * 2, segLeft, mid, left, right)
        val rightValue = getmin(ind * 2 + 1, mid + 1, segRight, left, right)
        return min(leftValue, rightValue)
    }
    
    fun binarySearch(ind: Int = 1, segLeft: Int = 1, segRight: Int = len, value: Int): Int {
        if (segLeft == segRight){
            return segLeft
        }
        propagateToChildren(ind, segLeft, segRight)
        val mid = (segLeft + segRight) / 2
        if (segmin[ind * 2] < value){
            return binarySearch(ind * 2, segLeft, mid, value)
        }
        else{
            return binarySearch(ind * 2 + 1, mid + 1, segRight, value)
        }
    }
    
    private fun propagateToChildren(ind: Int, segLeft: Int, segRight: Int) {
        if (lazy[ind] != 0) {
            val mid = (segLeft + segRight) / 2
            segsum[ind * 2] = lazy[ind].toLong() * (mid - segLeft + 1)
            segmin[ind * 2] = lazy[ind]
            segsum[ind * 2 + 1] = lazy[ind].toLong() * (segRight - mid)
            segmin[ind * 2 + 1] = lazy[ind]
            lazy[ind * 2] = lazy[ind]
            lazy[ind * 2 + 1] = lazy[ind]
            lazy[ind] = 0
        }
    }
}

fun main(args: Array<String>) {
    val n = readInt()
    val a = readInts()
    val q = readInt()
    var queries = Array(n + 1) { _ -> MutableList <Pair <Int, Int>>(0) { _ -> Pair(0, 0)}}
    for (i in 0..q-1){
        val (l, r) = readInts()
        queries[r].add(Pair(l, i))
    }
    var cac = SegmentTree(n + 1)
    var ans = LongArray(q)
    for (i in 0..n-1){
        val pos = cac.binarySearch(1, 1, n, a[i])
        cac.update(1, a[i], 1, n, pos, i + 1)
        for (query in queries[i + 1]){
            ans[query.second] = cac.getsum(1, 1, n, query.first, i + 1)
        }
    }
    println(ans.joinToString(" "))
}