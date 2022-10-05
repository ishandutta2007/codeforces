import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val prev0 = mutableMapOf<String, BitSet>()
    val prev1 = mutableMapOf<String, BitSet>()
    prev0["?"] = BitSet(m)
    val all = BitSet(m)
    all.set(0, m)
    prev1["?"] = all
    val amt0 = IntArray(m)
    val amt1 = IntArray(m)
    for (j in 1..n) {
        val line = jin.readLine().split(" ")
        if (line.size == 3) {
            val bitSet = BitSet(m)
            for (k in 0 until m) {
                if (line[2][k] == '1') {
                    bitSet.set(k)
                    amt0[k]++
                    amt1[k]++
                }
            }
            prev0[line[0]] = bitSet
            prev1[line[0]] = bitSet
        } else {
            val bitSet0 = BitSet(m)
            val bitSet1 = BitSet(m)
            bitSet0.or(prev0[line[2]]!!)
            bitSet1.or(prev1[line[2]]!!)
            if (line[3][0] == 'A') {
                bitSet0.and(prev0[line[4]]!!)
                bitSet1.and(prev1[line[4]]!!)
            } else if (line[3][0] == 'O') {
                bitSet0.or(prev0[line[4]]!!)
                bitSet1.or(prev1[line[4]]!!)
            } else {
                bitSet0.xor(prev0[line[4]]!!)
                bitSet1.xor(prev1[line[4]]!!)
            }
            prev0[line[0]] = bitSet0
            prev1[line[0]] = bitSet1
            for (k in 0 until m) {
                if (bitSet0.get(k)) {
                    amt0[k]++
                }
                if (bitSet1.get(k)) {
                    amt1[k]++
                }
            }
        }
    }
    val answerMin = StringBuilder()
    val answerMax = StringBuilder()
    for (k in 0 until m) {
        if (amt0[k] < amt1[k]) {
            answerMin.append('0')
            answerMax.append('1')
        } else if (amt0[k] == amt1[k]) {
            answerMin.append('0')
            answerMax.append('0')
        } else {
            answerMin.append('1')
            answerMax.append('0')
        }
    }
    println(answerMin)
    println(answerMax)
}