import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        var intervalLeft = 1L
        var intervalRight = Int.MAX_VALUE.toLong()
        val treeSet = TreeSet<Long>()
        var answer = (2 * n) + 1
        val tokenizer = StringTokenizer(jin.readLine())
        var sign = true
        var constant = 0L
        for (j in 1..n) {
            val k = tokenizer.nextToken().toLong()
            if (sign) {
                if (k % 2L == 0L) {
                    val h = k / 2L
                    if (h - constant in intervalLeft..intervalRight || h - constant in treeSet) {
                        answer -= 2
                        intervalLeft = h - constant
                        intervalRight = h - constant
                        treeSet.clear()
                        treeSet.add(h - constant)
                    } else {
                        answer--
                        treeSet.add(h - constant)
                        intervalLeft = max(intervalLeft, 1L - constant)
                        intervalRight = min(intervalRight, k - 1L - constant)
                        while (treeSet.isNotEmpty() && treeSet.first() < 1L - constant) {
                            treeSet.remove(treeSet.first())
                        }
                        while (treeSet.isNotEmpty() && treeSet.last() > k - 1L - constant) {
                            treeSet.remove(treeSet.last())
                        }
                    }
                } else {
                    intervalLeft = max(intervalLeft, 1L - constant)
                    intervalRight = min(intervalRight, k - 1L - constant)
                    while (treeSet.isNotEmpty() && treeSet.first() < 1L - constant) {
                        treeSet.remove(treeSet.first())
                    }
                    while (treeSet.isNotEmpty() && treeSet.last() > k - 1L - constant) {
                        treeSet.remove(treeSet.last())
                    }
                    if (intervalLeft > intervalRight && treeSet.isEmpty()) {
                        intervalLeft = 1L - constant
                        intervalRight = k - 1L - constant
                    } else {
                        answer--
                    }
                }
            } else {
                if (k % 2L == 0L) {
                    val h = k / 2L
                    if (constant - h in intervalLeft..intervalRight || constant - h in treeSet) {
                        answer -= 2
                        intervalLeft = constant - h
                        intervalRight = constant - h
                        treeSet.clear()
                        treeSet.add(constant - h)
                    } else {
                        answer--
                        treeSet.add(constant - h)
                        intervalLeft = max(intervalLeft, constant - (k - 1L))
                        intervalRight = min(intervalRight, constant - 1L)
                        while (treeSet.isNotEmpty() && treeSet.first() < constant - (k - 1L)) {
                            treeSet.remove(treeSet.first())
                        }
                        while (treeSet.isNotEmpty() && treeSet.last() > constant - 1L) {
                            treeSet.remove(treeSet.last())
                        }
                    }
                } else {
                    intervalLeft = max(intervalLeft, constant - (k - 1L))
                    intervalRight = min(intervalRight, constant - 1L)
                    while (treeSet.isNotEmpty() && treeSet.first() < constant - (k - 1L)) {
                        treeSet.remove(treeSet.first())
                    }
                    while (treeSet.isNotEmpty() && treeSet.last() > constant - 1L) {
                        treeSet.remove(treeSet.last())
                    }
                    if (intervalLeft > intervalRight && treeSet.isEmpty()) {
                        intervalLeft = constant - (k - 1L)
                        intervalRight = constant - 1L
                    } else {
                        answer--
                    }
                }
            }
            constant = k - constant
            sign = !sign
        }
        out.appendln(answer)
    }
    print(out)
}