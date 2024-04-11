import java.util.*

const val MOD = 1000000007L

fun main() {
    var line = readLine()!!
    var six = line.indexOf(' ')
    val n = line.substring(0, six).toInt()
    val m = line.substring(six + 1).toInt()
    val tokenizer = StringTokenizer(readLine()!!)
    val sweetness = IntArray(n) { tokenizer.nextToken().toInt() }
    val fromLeft = Array(n) { Cow(0, 0, 0) }
    val fromRight = Array(n) { Cow(0, 0, 0) }
    for (j in 1..m) {
        line = readLine()!!
        six = line.indexOf(' ')
        val f = line.substring(0, six).toInt()
        val h = line.substring(six + 1).toInt()
        var left = 0
        var ht = h
        while (left < n) {
            if (sweetness[left] == f) {
                ht--
            }
            if (ht == 0) {
                break
            }
            left++
        }
        var right = n - 1
        ht = h
        while (right >= 0) {
            if (sweetness[right] == f) {
                ht--
            }
            if (ht == 0) {
                break
            }
            right--
        }
        if (left < n) {
            val cow = Cow(left, right, f)
            fromLeft[left] = cow
            fromRight[right] = cow
        }
    }
    var maxAmt = 0
    var answer = 0L
    for (j in 0..n) {
        val leftAmt = IntArray(n + 1)
        val rightAmt = IntArray(n + 1)
        val bothAmt = IntArray(n + 1)
        val type = IntArray(n + 1)
        for (left in 0 until j) {
            leftAmt[fromLeft[left].f]++
            if (fromLeft[left].right >= j) {
                bothAmt[fromLeft[left].f]++
            }
        }
        for (right in j until n) {
            rightAmt[fromRight[right].f]++
        }
        var amt = 0
        var currWays = 1L
        for (f in 1..n) {
            var localWays = (leftAmt[f] * rightAmt[f]) - bothAmt[f]
            if (localWays > 0) {
                type[f] = 2
            } else {
                localWays = leftAmt[f] + rightAmt[f]
                if (localWays > 0) {
                    type[f] = 1
                } else {
                    localWays = 1
                }
            }
            amt += type[f]
            currWays *= localWays.toLong()
            currWays %= MOD
        }
        //println("j = $j, amt = $amt, currWays = $currWays")
        if (amt < maxAmt) {
            continue
        } else if (amt > maxAmt) {
            maxAmt = amt
            answer = 0L
        }
        answer += currWays
        answer %= MOD
        //println("j = $j, amt = $amt, currWays = $currWays, answer = $answer")
        var sign = 1L
        if (j + 1 <= n) {
            val k = j + 1
            sign *= -1L
            val cow = fromRight[k - 1]
            val f = cow.f
            if (f != 0) {
                if (type[f] == 2) {
                    var localWays = (leftAmt[f] * rightAmt[f]) - bothAmt[f]
                    currWays *= inverse(localWays)
                    currWays %= MOD
                    rightAmt[f]--
                    if (cow.left < j) {
                        bothAmt[f]--
                    }
                    localWays = (leftAmt[f] * rightAmt[f]) - bothAmt[f]
                    currWays *= localWays.toLong()
                    currWays %= MOD
                } else {
                    var localWays = leftAmt[f] + rightAmt[f]
                    currWays *= inverse(localWays)
                    currWays %= MOD
                    rightAmt[f]--
                    if (cow.left < j) {
                        bothAmt[f]--
                    }
                    localWays = leftAmt[f] + rightAmt[f]
                    currWays *= localWays.toLong()
                    currWays %= MOD
                }
            }
            answer += currWays * sign
            answer %= MOD
            //println("j = $j, k = $k, currWays = $currWays, answer = $answer")
        }
    }
    println("$maxAmt $answer")
}

data class Cow(val left: Int, val right: Int, val f: Int)

fun inverse(k: Int): Long {
    var e = 1000000005
    var b = k.toLong()
    var res = 1L
    while (e > 0) {
        if (e and 1 != 0) {
            res *= b
            res %= MOD
        }
        b *= b
        b %= MOD
        e = e shr 1
    }
    return res
}