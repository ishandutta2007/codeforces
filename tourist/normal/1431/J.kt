import java.lang.AssertionError

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}

private const val md = 998244353

private fun add(a: Int, b: Int) : Int {
    var c = a + b
    if (c >= md) {
        c -= md
    }
    return c
}

private fun mul(a: Int, b: Int) : Int {
    return (a.toLong() * b % md).toInt()
}

fun main(args: Array<String>) {
    var n = readInt()
    var a = readLongs()
    var START = System.currentTimeMillis()
    var goal = 0L
    for (x in a) {
        goal = goal xor x
    }
    var ans = 0
    for (mask in 0 until (1 shl (n - 1))) {
        var prefix = LongArray(n - 1)
        var limit = LongArray(n - 1)
        var lt = BooleanArray(n - 1)
        var ok = true
        for (i in 0 until n - 1) {
            var x = a[i] xor a[i + 1]
            if ((mask and (1 shl i)) != 0) {
                if (x == 0L) {
                    ok = false
                    break
                }
                prefix[i] = a[i + 1]
                lt[i] = true
            } else {
                prefix[i] = a[i]
                lt[i] = false
            }
            limit[i] = 1
            while (limit[i] shl 1 <= x) {
                limit[i] = limit[i] shl 1
            }
        }
        if (!ok) {
            continue
        }
/*        println(mask)
        println(prefix.joinToString(" "))
        println(limit.joinToString(" "))
        println(lt.joinToString(" "))*/
        var all = 0L
        for (i in 0 until n - 1) {
            all = all xor prefix[i]
        }
        if (all == goal) {
            ans = add(ans, 1)
        }
        var dp = Array(2) { IntArray(2) { 0 } }
        var newDp = Array(2) { IntArray(2) { 0 } }
        var z = goal
        for (i in 0 until n - 1) {
            z = z xor prefix[i]
        }
        for (bit in 0 until 60) {
            if (z shr (bit + 1) != 0L) {
                continue
            }
            var inGoal = ((goal shr bit) and 1L).toInt()
            dp[0][0] = 0
            dp[0][1] = 0
            dp[1][0] = 0
            dp[1][1] = 0
            dp[0][inGoal] = 1
            for (i in 0 until n - 1) {
                newDp[0][0] = 0
                newDp[0][1] = 0
                newDp[1][0] = 0
                newDp[1][1] = 0
                var me = ((prefix[i] shr bit) and 1L).toInt()
                var coeff = prefix[i]
                if (!lt[i]) {
                    coeff = coeff.inv()
                }
                coeff = (coeff and minOf((1L shl bit) - 1, limit[i] - 1)) + 1
                var coeff1 = (coeff % md).toInt()
                var coeff2 = ((1L shl bit) % md).toInt()
                for (any in 0 until 2) {
                    for (parity in 0 until 2) {
                        var ways = mul(dp[any][parity], coeff1)
                        newDp[any][parity xor me] = add(newDp[any][parity xor me], ways)
                        if (1L shl (bit + 1) <= limit[i]) {
                            if ((lt[i] && me == 1) || (!lt[i] && me == 0)) {
                                var ways = dp[any][parity]
                                if (any == 1) {
                                    ways = mul(ways, coeff2)
                                }
                                newDp[1][parity xor me xor 1] = add(newDp[1][parity xor me xor 1], ways)
                            }
                        }
                    }
                }
                dp[0][0] = newDp[0][0]
                dp[0][1] = newDp[0][1]
                dp[1][0] = newDp[1][0]
                dp[1][1] = newDp[1][1]
            }
            ans = add(ans, dp[1][0])
/*            if (dp[1][0] > 0) {
                println(bit.toString() + " " + dp[1][0].toString())
            }*/
        }
    }
    println(ans)
//    println(System.currentTimeMillis() - START)
}