    import kotlin.io.readLine
     
    fun main(args: Array<String>) {
        val t = readLine()!!.toInt()
        for (i in 1..t) {
    //        val line = readIntLine()
            val num = readLine()
    //        println(num!!.length)
            val ans = calcSummands(num)
    //        println(ans)
        }
    //    println(calcSummands("5009"))
    }
     
    fun calcSummands(n: String?) {
        println(n!!.filter { it != '0' }.length)
        var mutableN = n.toInt()
        var mult = 1
        println ((1..n.length).fold("") { acc, el ->
            val prev = mutableN
            mutableN /= 10
            mult *= 10
            if (prev % 10 == 0) acc else acc + " " + (prev % 10) * mult / 10 }.drop(1))
    }
     
    fun readIntLine(): List<Int> = readLine()!!.split(" ").map { it.toInt() }