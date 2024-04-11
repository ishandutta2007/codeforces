import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    fun check(bitsU: List<Int>, bitsV: List<Int>) = bitsU.size == bitsV.size && bitsV.indices.all { bitsU[it] <= bitsV[it] }
    for (c in 1..jin.readLine().toInt()) {
        val (u, v) = jin.readLine().split(" ").map { it.toInt() }
        val bitsU = (0 until 30).filter { (u shr it) and 1 == 1 }.toMutableList()
        val bitsV = (0 until 30).filter { (v shr it) and 1 == 1 }
        var answer = false
        if (bitsU.size > bitsV.size) {
            for (j in bitsU.size - bitsV.size until bitsU.size) {
                if (j == bitsU.lastIndex || bitsU[j + 1] > bitsU[j] + 1) {
                    val newBit = bitsU[j] + 1
                    val new = mutableListOf<Int>()
                    for (k in bitsU.indices) {
                        if (k == j) {
                            new.add(newBit)
                        } else if (k !in j - (bitsU.size - bitsV.size)..j) {
                            new.add(bitsU[k])
                        }
                    }
                    if (check(new, bitsV)) {
                        answer = true
                        break
                    }
                }
            }
        } else {
            answer = check(bitsU, bitsV)
        }
        out.appendln(if (answer) "yEs" else "nO")
    }
    print(out)
}