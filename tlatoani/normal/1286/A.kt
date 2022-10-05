import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    if (n == 1) {
        println(0)
        return
    }
    val p = IntArray(n) { jin.nextInt() }
    var last = 0
    var sep = 0
    val even2 = mutableListOf<Int>()
    val odd2 = mutableListOf<Int>()
    val even1 = mutableListOf<Int>()
    val odd1 = mutableListOf<Int>()
    var answer = 0
    var evenRem = n / 2
    var oddRem = n - evenRem
    for (j in 0 until n) {
        if (p[j] == 0) {
            sep++
        } else {
            if (p[j] % 2 == 0) {
                evenRem--
            } else {
                oddRem--
            }
            if (sep == 0) {
                if (j > 0 && (p[j] + p[j - 1]) % 2 != 0) {
                    answer++
                }
            } else {
                if (last == 0) {
                    when (p[j] % 2) {
                        0 -> even1
                        else -> odd1
                    }.add(sep)
                } else if ((p[j] + last) % 2 == 0) {
                    when (p[j] % 2) {
                        0 -> even2
                        else -> odd2
                    }.add(sep)
                } else {
                    answer++
                }
            }
            last = p[j]
            sep = 0
        }
    }
    if (sep > 0) {
        if (last == 0) {
            println(1)
            return
        }
        when (last % 2) {
            0 -> even1
            else -> odd1
        }.add(sep)
    }
    even2.sort()
    odd2.sort()
    even1.sort()
    odd1.sort()
    //println("$even2 $odd2 $even1 $odd1")
    while (true) {
        if (even2.isNotEmpty() && even2[0] <= evenRem && (even1.size < 2 || even1[0] + even1[1] > even2[0])) {
            evenRem -= even2[0]
            even2.removeAt(0)
        } else if (even1.isNotEmpty() && even1[0] <= evenRem) {
            evenRem -= even1[0]
            even1.removeAt(0)
        } else {
            break
        }
    }
    answer += (2 * even2.size) + even1.size
    while (true) {
        if (odd2.isNotEmpty() && odd2[0] <= oddRem && (odd1.size < 2 || odd1[0] + odd1[1] > odd2[0])) {
            oddRem -= odd2[0]
            odd2.removeAt(0)
        } else if (odd1.isNotEmpty() && odd1[0] <= oddRem) {
            oddRem -= odd1[0]
            odd1.removeAt(0)
        } else {
            break
        }
    }
    answer += (2 * odd2.size) + odd1.size
    println(answer)
}