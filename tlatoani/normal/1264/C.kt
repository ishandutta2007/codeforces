import java.util.*

fun main() {
    var tokenizer = StringTokenizer(readLine())
    val n = tokenizer.nextToken().toInt()
    val q = tokenizer.nextToken().toInt()
    val expecteds = Array(n + 1) { M0 }
    val products = Array(n + 1) { M1 }
    tokenizer = StringTokenizer(readLine())
    for (j in 0 until n) {
        var p = mint(tokenizer.nextToken().toInt())
        p = p pow -1
        p *= M100
        products[j + 1] = p * products[j]
        expecteds[j + 1] = p * (M1 + expecteds[j])
    }
    fun query(l: Int, r: Int) = expecteds[r] - (products[r] * (products[l] pow -1) * expecteds[l])
    val checkpoints = TreeSet<Int>()
    checkpoints.add(0)
    checkpoints.add(n)
    val answer = StringBuilder()
    var curr = query(0, n)
    for (j in 1..q) {
        val u = readLine()!!.toInt() - 1
        if (checkpoints.contains(u)) {
            checkpoints.remove(u)
            val l = checkpoints.floor(u)!!
            val r = checkpoints.ceiling(u)!!
            curr -= query(l, u)
            curr -= query(u, r)
            curr += query(l, r)
        } else {
            val l = checkpoints.floor(u)!!
            val r = checkpoints.ceiling(u)!!
            curr -= query(l, r)
            curr += query(l, u)
            curr += query(u, r)
            checkpoints.add(u)
        }
        answer.append(curr).append('\n')
    }
    print(answer)
}

val M0 = Mint(0)
val M1 = Mint(1)
val M2 = Mint(2)
val M100 = Mint(100)

val MOD: Long = 998244353
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