import java.io.*

const val ALPHA_SIZE = 26

fun process(str: String): Array<MutableList<Int>> {
    val res = Array(ALPHA_SIZE + 1) { mutableListOf<Int>() }
    for (i in str.indices) {
        res[if (str[i] == '?') ALPHA_SIZE else str[i] - 'a'].add(i + 1)
    }
    return res
}

fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = PrintWriter(System.out, false)

    val n = reader.readLine().toInt()

    val left = process(reader.readLine())
    val right = process(reader.readLine())

    val ans = mutableListOf<Pair<Int, Int>>()
    for (i in 0..ALPHA_SIZE) {
        for ((a, b) in listOf(i to i, i to ALPHA_SIZE, ALPHA_SIZE to i)) {
            while (left[a].isNotEmpty() && right[b].isNotEmpty()) {
                ans.add(left[a].last() to right[b].last())
                right[b].removeLast()
                left[a].removeLast()
            }
        }
    }

    writer.println(ans.size)
    for ((l, r) in ans) {
        writer.println("$l $r")
    }

    writer.close()
}