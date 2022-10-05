import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, q) = jin.readLine().split(" ").map { it.toInt() }
    val segTree = MatrixSegmentTree(n)
    for (j in 1..n) {
        val (a, b) = jin.readLine().split(" ").map { it.toInt() }
        val pInv = b.toDouble() / a.toDouble()
        segTree.update(j, Matrix(pInv - 1.0, 1.0))
    }
    val out = StringBuilder()
    for (j in 1..q) {
        val line = jin.readLine().split(" ").map { it.toInt() }
        if (line[0] == 1) {
            val pInv = line[3].toDouble() / line[2].toDouble()
            segTree.update(line[1], Matrix(pInv - 1.0, 1.0))
        } else {
            val matrix = segTree.query(line[1], line[2])
            out.appendln(if (matrix.det.isNaN() || matrix.d.isNaN()) 0 else 1.0 / (matrix.det + matrix.d))
        }
    }
    print(out)
}

data class Matrix(val det: Double, val d: Double) {

    operator fun times(other: Matrix) = Matrix(
            det * other.det,
            (det * other.d) + d
    )
}

val IDENTITY = Matrix(1.0, .0)

class MatrixSegmentTree(val n: Int) {
    val value = Array(270000) { IDENTITY }

    fun update(index: Int, delta: Matrix) = update(index, delta, 1, 1, n)

    fun update(index: Int, delta: Matrix, node: Int, segFrom: Int, segTo: Int) {
        if (segFrom == segTo) {
            value[node] = delta
        } else {
            val mid = (segFrom + segTo) / 2
            if (index <= mid) {
                update(index, delta, 2 * node, segFrom, mid)
            } else {
                update(index, delta, (2 * node) + 1, mid + 1, segTo)
            }
            value[node] = value[2 * node] * value[(2 * node) + 1]
        }
    }

    fun query(from: Int, to: Int) = query(from, to, 1, 1, n)

    fun query(from: Int, to: Int, node: Int, segFrom: Int, segTo: Int): Matrix {
        if (segTo < from || to < segFrom) {
            return IDENTITY
        } else if (from <= segFrom && segTo <= to) {
            return value[node]
        } else {
            val mid = (segFrom + segTo) / 2
            return query(from, to, 2 * node, segFrom, mid) * query(from, to, (2 * node) + 1, mid + 1, segTo)
        }
    }
}

/*

3 1
1 3
1 2
2 3
2 1 1


 */