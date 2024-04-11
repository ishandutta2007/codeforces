fun main() {
    val jin = FastScanner(true)
    val n = jin.nextInt()
    fun query(a: Int, b: Int): Int {
        println("? ${a + 1} ${b + 1}")
        return jin.nextInt()
    }
    val answer = IntArray(n)
    var k = 0
    for (j in 1 until n) {
        val a = query(k, j)
        val b = query(j, k)
        if (a > b) {
            answer[k] = a
            k = j
        } else {
            answer[j] = b
        }
    }
    answer[k] = n
    println("! " + answer.joinToString(" "))
}

class FastScanner(BS: Int) {
    private val buf = ByteArray(BS)
    private var bId = 0
    private var size = 0
    private var c = 0.toChar()

    constructor() : this(1 shl 20)

    constructor(interactive: Boolean) : this(if (interactive) 16 else (1 shl 20))

    private val char: Char
        private get() {
            if (bId == size) {
                size = try {
                    System.`in`!!.read(buf)
                } catch (e: Exception) {
                    return 0.toChar()
                }
                if (size == -1) return 0.toChar()
                bId = 0
            }
            return buf[bId++].toChar()
        }

    fun nextInt(): Int {
        var neg = false
        c = char
        while (c == '\n') {
            c = char
        }
        if (c == '-') {
            neg = true
            c = char
        }
        var res = 0
        while (c in '0'..'9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }

    fun nextLong(): Long {
        var neg = false
        c = char
        if (c == '-') {
            neg = true
            c = char
        }
        var res = 0L
        while (c in '0'..'9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }

    fun nextToken(length: Int): CharArray {
        val res = CharArray(length) { char }
        char
        return res
    }

    fun nextToken(): String {
        val builder = StringBuilder()
        c = char
        while (c != ' ' && c != '\n') {
            builder.append(c)
            c = char
        }
        return builder.toString()
    }

    fun nextLine(): String {
        val builder = StringBuilder()
        c = char
        while (c != '\n') {
            builder.append(c)
            c = char
        }
        return builder.toString()
    }
}