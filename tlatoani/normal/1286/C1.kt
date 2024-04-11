import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    if (n == 1) {
        println("? 1 1")
        println("! ${jin.next()}")
        return
    } else if (n == 2) {
        println("? 1 1")
        val s = jin.next()
        println("? 2 2")
        val t = jin.next()
        println("! $s$t")
        return
    }
    val a = 1
    val b = (n - 1) / 2
    println("? $a $b")
    val pos1 = getPossible(jin, b - a + 1)
    val c = b + 1
    val d = n
    println("? $c $d")
    val pos2 = getPossible(jin, d - c + 1)
    val e = max((b - 1) / 2, 1)
    val f = b + ((d - b) / 2)
    println("? $e $f")
    val pos3 = getPossible(jin, f - e + 1)
    for (s in pos1) {
        for (t in pos2) {
            for (u in pos3) {
                if (s.substring(e - 1) == u.substring(0, b - e + 1) && u.substring(c - e) == t.substring(0, f - c + 1)) {
                    println("! ${s + t}")
                    return
                }
                //println("$s $u $t")
                //println(">> ${s.substring(e - 1)} ${u.substring(0, b - e + 1)} ${u.substring(c - e)} ${t.substring(0, f - (c - e))}")
            }
        }
    }
    println("fail")
}

fun getPossible(jin: Scanner, l: Int): List<String> {
    val freq = Array(26) { IntArray(l + 1) }
    val substrings = mutableMapOf<Long, Int>()
    for (j in 1..(l * (l + 1)) / 2) {
        var s = jin.next().toList().sorted().joinToString("")
        var hash = 0L
        for (chara in s) {
            hash += 1L shl (2 * (chara - 'a'))
        }
        hash += s.length.toLong() shl 60
        substrings[hash] = (substrings[hash] ?: 0) + 1
        for (chara in s) {
            freq[chara - 'a'][s.length]++
        }
    }
    val pos = Array(((l + 1) / 2) + 1) { mutableListOf<Int>() }
    for (j in 0..25) {
        val times = IntArray(((l + 1) / 2) + 1)
        var occ = freq[j][1]
        for (k in 2..(l + 1) / 2) {
            while (freq[j][k] < occ * k) {
                times[k - 1]++
                occ--
                for (a in k..(l + 1) / 2) {
                    freq[j][a] -= k - 1
                }
            }
        }
        times[(l + 1) / 2] += occ
        for (k in 1..(l + 1) / 2) {
            if (times[k] > 0) {
                pos[k].add(j)
            }
        }
    }
    val res = mutableListOf<String>()
    val stack = Stack<Node>()
    stack.push(Node("", mutableMapOf()))
    while (!stack.isEmpty()) {
        val node = stack.pop()
        //println(node)
        if (node.s.length == l) {
            res.add(node.s)
        } else {
            val j = min(node.s.length + 1, l - node.s.length)
            for (c in pos[j]) {
                val chara = 'a' + c
                val next = Node(node.s + chara, node.substrings.toMutableMap())
                var works = true
                var hash = 0L
                for (k in next.s.length - 1 downTo 0) {
                    hash += 1L shl 60
                    hash += 1L shl (2 * (next.s[k] - 'a'))
                    next.substrings[hash] = (next.substrings[hash] ?: 0) + 1
                    if (next.substrings[hash]!! > (substrings[hash] ?: 0)) {
                        works = false
                        break
                    }
                }
                if (works) {
                    stack.push(next)
                }
            }
        }
    }
    return res
}

data class Node(val s: String, val substrings: MutableMap<Long, Int>)
/*
abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz
 */