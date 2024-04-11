import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

class SegmentTree{

    private val tree: IntArray
    private val len: Int

    /**
     * Creates an empty segment tree
     *
     * @param size Size of relevant range
     */
    constructor(size: Int) {
        tree = IntArray(size * 4)
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
    fun update(ind: Int = 1, value: Int, segLeft: Int = 1, segRight: Int = len, idx: Int) {
        if (segLeft > idx || segRight < idx || segLeft > segRight) {
            return
        }
        if (idx <= segLeft && segRight <= idx) {
            tree[ind] = value
        } else {
            val mid = (segLeft + segRight) / 2
            update(ind * 2, value, segLeft, mid, idx)
            update(ind * 2 + 1, value, mid + 1, segRight, idx)
            tree[ind] = max(tree[ind * 2], tree[ind * 2 + 1])
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
    fun get(ind: Int = 1, segLeft: Int = 1, segRight: Int = len, left: Int, right: Int): Int {
        if (segLeft > right || segRight < left || segLeft > segRight) {
            return 0
        }
        if (left <= segLeft && segRight <= right) {
            return tree[ind]
        }
        val mid = (segLeft + segRight) / 2
        val leftValue = get(ind * 2, segLeft, mid, left, right)
        val rightValue = get(ind * 2 + 1, mid + 1, segRight, left, right)
        return max(leftValue, rightValue)
    }
}

fun main(args: Array<String>) {
    val q = readInt()
    repeat(q){
        val n = readInt()
        val a = readInts()
        var l = Array(n + 1) { i -> -1 }
        var r = Array(n + 1) { i -> -1 }
        for (i in 0..n-1){
            if (l[a[i]] == -1){
                l[a[i]] = i
            }
            else{
                r[a[i]] = i
            }
        }
        var cac = SegmentTree(n)
        var ans = 0
        for (i in 0..n-1){
            var tans = 0;
            cac.update(1, 1, 1, n, i + 1)
            if (l[a[i]] == i){
                tans = 1;
            }
            else{
                tans = 2 + cac.get(1, 1, n, l[a[i]] + 2, i)
                cac.update(1, tans, 1, n, l[a[i]] + 1)
            }
            ans = max(ans, tans)
        }
        println(ans)
    }
}