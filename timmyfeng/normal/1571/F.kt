fun main() {
    var (n, m) = readLine()!!.split(" ").map { it.toInt() }

    val length = mutableListOf<Int>()
    val index = mutableListOf<Int>()
    val startDays = IntArray(n)
    var totalSum = 0

    for (i in 0 until n) {
        val (k, t) = readLine()!!.split(" ").map { it.toInt() }

        if (t == 1) {
            m -= k
            startDays[i] = m + 1
        } else {
            totalSum += k
            length.add(k)
            index.add(i)
        }
    }
    
    if (m < 0) {
        println(-1)
        return
    }

    n = length.size

    val possibleSum = Array(n + 1) { BooleanArray(m + 1) }
    possibleSum[0][0] = true

    for (i in 0 until n) {
        for (j in 0..m) {
            if (possibleSum[i][j]) {
                if (j + length[i] <= m) {
                    possibleSum[i + 1][j + length[i]] = true
                }
                possibleSum[i + 1][j] = true
            }
        }
    }

    var evenSum = -1
    for (i in 0..m) {
        if (possibleSum[n][i] && i <= m / 2 && totalSum - i <= (m + 1) / 2) {
            evenSum = i
            break
        }
    }

    if (evenSum == -1) {
        println(-1)
        return
    }

    var oddPtr = 1
    var evenPtr = 2
    for (i in n - 1 downTo 0) {
        if (possibleSum[i][evenSum]) {
            startDays[index[i]] = oddPtr
            oddPtr += 2 * length[i]
        } else {
            startDays[index[i]] = evenPtr
            evenPtr += 2 * length[i]
            evenSum -= length[i]
        }
    }

    println(startDays.joinToString(" "))
}