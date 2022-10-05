//package codeforces.edu75

import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val startTime = System.currentTimeMillis()
    val perm = IntArray(1 shl POWER) { j ->
        var k = 0
        for (l in 0 until POWER) {
            if ((j and (1 shl l)) != 0) {
                k += 1 shl (POWER - l - 1)
            }
        }
        k
    }
    val afterTime = System.currentTimeMillis()
    //println("that array thing time = ${afterTime - startTime}")
    val k = jin.nextInt()
    val boards = Array(n + k) { j -> if (j < n) Board(0, jin.nextInt()) else Board(-1, jin.nextInt()) }
    boards.sort()
    val q = jin.nextInt()
    val special = IntArray(q) { jin.nextInt() / 2 }
    val answer = Array(q) { M0 }
    val factorial = Array(300001) { j -> mint(j) }
    factorial[0] = M1
    for (j in 1..300000) {
        factorial[j] *= factorial[j - 1]
    }
    fun choose(n: Int, k: Int) = factorial[n] / (factorial[k] * factorial[n - k])
    val freq = IntArray(300001)
    var c = 0
    var d = 0
    for (board in boards) {
        if (board.color == 0) {
            freq[board.length]++
            if (freq[board.length] == 2) {
                c--
                d++
            } else if (freq[board.length] == 1) {
                c++
            }
        } else {
            for (j in 0 until (1 shl POWER)) {
                fftArray1[perm[j]] = (if (j <= c) (M2 pow j) * choose(c, j) else M0).num.toInt()
                fftArray2[perm[j]] = (if (j <= 2 * d) choose(2 * d, j) else M0).num.toInt()
            }
            multiplyPolynomials()
            for (j in 0 until q) {
                if (special[j] > board.length && special[j] - board.length - 1 < fftArray1.size) {
                    answer[j] += mint((fftArray1[perm[special[j] - board.length - 1]] % MODI) + MODI)
                }
            }
        }
    }
    println(answer.joinToString("\n", "", ""))
    val endTime = System.currentTimeMillis()
    //println("total time = ${endTime - startTime}")
}

data class Board(val color: Int, val length: Int): Comparable<Board> {
    override fun compareTo(other: Board) = compareValuesBy(this, other, { it.length }, { it.color })
}

const val POWER = 19
val PRIMITIVE_ROOT = mint(363395222) pow 1

val fftArray1 = IntArray(1 shl POWER)
val fftArray2 = IntArray(1 shl POWER)

fun fft(array: IntArray) {
    val startTime = System.currentTimeMillis()
    for (k in 1..POWER) {
        val half = 1 shl (k - 1)
        var omega = PRIMITIVE_ROOT pow (1 shl (POWER - k))
        var l = 0
        while (l < array.size) {
            var w = M1
            for (j in l until l + half) {
                val g = array[j]
                val h = ((w.num * array[j + half].toLong()) % MOD).toInt()
                array[j] = (g + h) % MODI
                array[j + half] = (g - h + MODI) % MODI
                w *= omega
            }
            l += 2 * half
        }
    }
    val endTime = System.currentTimeMillis()
    //println("codeforces.edu75.fft time = ${endTime - startTime}")
}

fun fftInverse(array: IntArray) {
    val startTime = System.currentTimeMillis()
    for (k in POWER downTo 1) {
        val half = 1 shl (k - 1)
        var omega = PRIMITIVE_ROOT pow (-1 shl (POWER - k))
        var l = 0
        while (l < array.size) {
            var w = M1
            for (j in l until l + half) {
                val g = (array[j] + array[j + half])
                val h = w.num * (array[j] - array[j + half]).toLong()
                array[j] = g % MODI
                array[j + half] = (h % MOD).toInt()
                w *= omega
            }
            l += 2 * half
        }
    }
    val factor = (M2 pow -POWER).num
    for (j in 0 until array.size) {
        array[j] = ((array[j].toLong() * factor) % MOD).toInt()
    }
    val endTime = System.currentTimeMillis()
    //println("codeforces.edu75.fft inverse time = ${endTime - startTime}")
}

fun multiplyPolynomials() {
    fft(fftArray1)
    fft(fftArray2)
    for (j in 0 until (1 shl POWER)) {
        fftArray1[j] = ((fftArray1[j].toLong() * fftArray2[j].toLong()) % MOD).toInt()
    }
    fftInverse(fftArray1)
}

val M0 = Mint(0)
val M1 = Mint(1)
val M2 = Mint(2)

val MODI = 998244353
val MOD = MODI.toLong()
val MOD_TOTIENT = (MOD - 1).toInt()

fun mint(num: Long) = Mint(num % MOD)
fun mint(num: Int) = Mint(num % MOD)

inline class Mint(val num: Long) {

    operator fun plus(k: Mint) = mint(num + k.num)
    operator fun minus(k: Mint) = mint(num + MOD - k.num)
    operator fun times(k: Mint) = mint(num * k.num)
    operator fun div(k: Mint) = this * (k pow -1)

    operator fun unaryMinus() = mint(MOD - num)
    operator fun inc() = this + M1
    operator fun dec() = this - M1

    infix fun pow(power: Int): Mint {
        var e = power
        e %= MOD_TOTIENT
        if (e < 0) {
            e += MOD_TOTIENT
        }
        if (e == 0 && num == 0L) {
            return this
        }
        var b = this
        var res = Mint(1)
        while (e > 0) {
            if (e and 1 != 0) {
                res *= b
            }
            b *= b
            e = e shr 1
        }
        return res
    }

    override fun toString(): String = num.toString()
}