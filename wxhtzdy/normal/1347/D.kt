

    import java.lang.IllegalStateException
    import java.util.*
    import kotlin.io.readLine
     
    fun main(args: Array<String>) {
        val t = readLine()!!.toInt()
        for (i in 1..t) {
            readLine()
            val arr = readIntLine()
            calc(arr)
    //        println(journeyToMoon(np[0], edges))
    //        println(ans)
        }
    //    println(shop(5, 5, listOf("1 1", "1 2", "1 3", "1 4", "1 5").toTypedArray(), listOf(
    //        listOf(1, 2, 10).toTypedArray(),
    //        listOf(1, 3, 10).toTypedArray(),
    //        listOf(2, 4, 10).toTypedArray(),
    //        listOf(1, 5, 10).toTypedArray(),
    //        listOf(4, 5, 10).toTypedArray()
    //    ).toTypedArray()))
    //    calc("1 2 3 4 5 6 7 8 9 10 11 12 13".split(" ").map { it.toInt() })
    }
     
    fun calc(arr: List<Int>) {
        var bobAcc = 0
        var aliceAcc = 0
        var moves = 0
        fun tailRec(leftInd: Int, rightInd: Int, prev: Int, leftMove: Boolean, acc: Int) {
            if (leftInd - 1 != rightInd) {
                if (acc > prev) {
                    moves++
                    if (leftMove) aliceAcc += acc else bobAcc += acc
                    tailRec(leftInd, rightInd, acc, !leftMove, 0)
                } else tailRec(if (leftMove) leftInd + 1 else leftInd, if (!leftMove) rightInd - 1 else rightInd,
                    prev, leftMove, if (leftMove) acc + arr[leftInd] else acc + arr[rightInd])
            } else {
                moves++
                if (leftMove) aliceAcc += acc else bobAcc += acc
            }
        }
     
        tailRec(0, arr.size - 1, 0, true, 0)
        println("$moves $aliceAcc $bobAcc")
    }
     
    fun readIntLine(): List<Int> = readLine()!!.split(" ").map { it.toInt() }