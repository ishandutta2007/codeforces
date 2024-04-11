import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun mind(a: Int, b: Int): Int {
    if (a == -1) {
        return b
    }
    if (b == -1) {
        return a
    }
    return min(a, b)
}

fun comb(a: Int, b: Int): Int {
    if (a == -1 || b == -1) {
        return -1
    }
    return a + b
}

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var tokenizer = StringTokenizer(jin.readLine())
    val n = tokenizer.nextToken().toInt()
    val k = tokenizer.nextToken().toInt()
    val s = jin.readLine()
    val initial = IntArray(n + 1) { if (it == 0) 0 else ('1' - s[it - 1]) }
    val subset1 = IntArray(n + 1)
    val subset2 = IntArray(n + 1)
    for (j in 1..k) {
        val c = jin.readLine().toInt()
        tokenizer = StringTokenizer(jin.readLine())
        for (g in 1..c) {
            val x = tokenizer.nextToken().toInt()
            if (subset1[x] == 0) {
                subset1[x] = j
            } else {
                subset2[x] = j
            }
        }
    }
    val needed = Array(2) { b -> IntArray(k + 1) { b } }
    val union = IntArray(k + 1) { it }
    val unionBit = IntArray(k + 1)
    fun getUnion(j: Int): Int {
        if (union[j] != union[union[j]]) {
            val prev = union[j]
            union[j] = getUnion(union[j])
            unionBit[j] = unionBit[j] xor unionBit[prev]
        }
        return union[j]
    }
    val out = StringBuilder()
    var curr = 0
    for (j in 1..n) {
        if (subset2[j] != 0) {
            val a = getUnion(subset1[j])
            val b = getUnion(subset2[j])
            if (a != b) {
                curr -= mind(needed[0][a], needed[1][a])
                curr -= mind(needed[0][b], needed[1][b])
                unionBit[a] = unionBit[subset1[j]] xor unionBit[subset2[j]] xor initial[j]
                needed[0][b] = comb(needed[0][b], needed[unionBit[a]][a])
                needed[1][b] = comb(needed[1][b], needed[1 - unionBit[a]][a])
                union[a] = b
                curr += mind(needed[0][b], needed[1][b])
            }
        } else if (subset1[j] != 0) {
            val a =  getUnion(subset1[j])
            curr -= mind(needed[0][a], needed[1][a])
            needed[unionBit[subset1[j]] xor initial[j] xor 1][a] = -1
            curr += mind(needed[0][a], needed[1][a])
        }
        out.appendln(curr)
    }
    print(out)
}