import java.lang.StringBuilder
import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val sequence = IntArray(n) { jin.nextInt() }
    val freq = mutableMapOf<Int, Int>()
    for (k in sequence) {
        freq[k] = (freq[k] ?: 0) + 1
    }
    var upper = 1
    while ((freq[upper] ?: 0) == 2) {
        upper++
    }
    upper--
    var lower = 0
    while (upper > lower) {
        val mid = (upper + lower + 1) / 2
        val seen = mutableSetOf<Int>()
        val list = mutableListOf<Int>()
        var j = 0
        var works = true
        //println("mid = $mid")
        for (k in sequence) {
            if (k <= mid) {
                if (seen.contains(k)) {
                    if (list[j] == k) {
                        j++
                    } else {
                        works = false
                        break
                    }
                } else {
                    list += k
                    seen.add(k)
                }
            }
            //println("k = $k, j = $j, list = $list")
        }
        if (list.size < mid || j < mid) {
            works = false
        }
        if (works) {
            lower = mid
        } else {
            upper = mid - 1
        }
    }
    val seen = mutableSetOf<Int>()
    val answer = StringBuilder()
    for (k in sequence) {
        if (k <= upper) {
            if (seen.contains(k)) {
                answer.append('G')
            } else {
                seen.add(k)
                answer.append('R')
            }
        } else {
            answer.append('B')
        }
    }
    println(answer)
}