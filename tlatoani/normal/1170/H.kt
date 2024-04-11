import java.lang.StringBuilder
import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val builder = StringBuilder()
    for (c in 1..jin.nextInt()) {
        val n = jin.nextInt()
        val array = Array(n) { jin.nextInt() }
        array.sort()
        if (array[n / 2] != array[(n - 1) / 2]) {
            builder.append(n)
            builder.append('\n')
            for (i in 0 until n) {
                if (i > 0) {
                    builder.append(' ')
                }
                if (i % 2 == 0) {
                    builder.append(array[(i / 2)])
                } else {
                    builder.append(array[(n + i) / 2])
                }
            }
            builder.append('\n')
            continue
        }
        val mid = n / 2
        var l = mid
        while (l >= 0 && array[l] == array[mid]) {
            l--
        }
        l++
        var r = mid
        while (r < n && array[r] == array[mid]) {
            r++
        }
        r--
        val joiner = StringJoiner(" ")
        if (l == 0) {
            builder.append((2 * (n - 1 - r)) + 1)
            for (i in 0 until n - 1 - r) {
                joiner.add("" + array[mid])
                joiner.add("" + array[n - 1 - i])
            }
            joiner.add("" + array[mid])
        } else if (r == n - 1) {
            builder.append((2 * l) + 1)
            for (i in 0 until l) {
                joiner.add("" + array[mid])
                joiner.add("" + array[i])
            }
            joiner.add("" + array[mid])
        } else if (r - l + 1 < (n + 1) / 2) {
            builder.append(n)
            for (i in 0 until n) {
                if (i % 2 == 0) {
                    joiner.add("" + array[mid + (i / 2)])
                } else {
                    joiner.add("" + array[i / 2])
                }
            }
        } else {
            builder.append((l + n - 1 - r) * 2)
            for (i in 0 until l) {
                joiner.add("" + array[mid])
                joiner.add("" + array[i])
            }
            for (i in r + 1 until n) {
                joiner.add("" + array[i])
                joiner.add("" + array[mid])
            }
        }
        builder.append('\n')
        builder.append(joiner)
        builder.append('\n')
    }
    print(builder)
}