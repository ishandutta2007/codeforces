import java.util.*
import kotlin.math.min

fun main() {
    val s = readLine()!!
    val x = readLine()!!.toInt()
    val states = mutableMapOf<String, Int>()
    var stateAMT = 0
    var ll = LinkedList<Int>()
    fun recur() {
        states[ll.joinToString("")] = stateAMT
        stateAMT++
        for (d in 1..9) {
            ll.addFirst(d)
            var sum = 0
            var isNew = true
            for (j in ll) {
                sum += j
                if (x % sum == 0) {
                    isNew = false
                    break
                }
            }
            if (isNew && sum < x) {
                recur()
            }
            ll.removeFirst()
        }
    }
    recur()
    val next = Array(10) { IntArray(stateAMT) }
    for ((state, k) in states) {
        for (d in 1..9) {
            var new = d.toString() + state
            var brack = -2
            var sum = 0
            for (j in new.indices) {
                sum += new[j] - '0'
                if (sum == x) {
                    brack = -1
                    break
                } else if (x % sum == 0 || sum > x) {
                    brack = j
                    break
                }
            }
            if (brack == -1) {
                next[d][k] = -1
            } else {
                if (brack != -2) {
                    new = new.substring(0, brack)
                }
                next[d][k] = states[new]!!
            }
        }
    }
    var dpPrev = IntArray(stateAMT) { 2000 }
    dpPrev[0] = 0
    var dpNext = IntArray(stateAMT)
    for (chara in s) {
        val d = chara - '0'
        for (s in 0 until stateAMT) {
            dpNext[s] = dpPrev[s] + 1
        }
        for (s in 0 until stateAMT) {
            if (next[d][s] != -1) {
                dpNext[next[d][s]] = min(dpNext[next[d][s]], dpPrev[s])
            }
        }
        val temp = dpPrev
        dpPrev = dpNext
        dpNext = temp
    }
    println(dpPrev.min())
}