import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val outside = mutableListOf<Point>()
    val inside = mutableListOf<Point>()
    for (j in 3..n) {
        println("2 1 2 $j")
        val sign = jin.nextInt()
        println("1 1 2 $j")
        val area = jin.nextLong()
        if (sign == 1) {
            outside.add(Point(j, area))
        } else {
            inside.add(Point(j, area))
        }
    }
    outside.sortBy { it.area }
    inside.sortBy { it.area }
    val answer = mutableListOf<Int>()
    answer.add(0)
    answer.add(1)
    val toAdd = mutableListOf<Int>()
    if (inside.isNotEmpty()) {
        for (p in inside) {
            if (p.ix == inside.last().ix) {
                continue
            }
            println("2 1 ${inside.last().ix} ${p.ix}")
            if (jin.nextInt() == 1) {
                toAdd.add(p.ix)
            } else {
                answer.add(p.ix)
            }
        }
        answer.add(inside.last().ix)
        answer.addAll(toAdd.reversed())
        toAdd.clear()
    }
    answer.add(2)
    if (outside.isNotEmpty()) {
        for (p in outside) {
            if (p.ix == outside.last().ix) {
                continue
            }
            println("2 1 ${outside.last().ix} ${p.ix}")
            if (jin.nextInt() == 1) {
                toAdd.add(p.ix)
            } else {
                answer.add(p.ix)
            }
        }
        answer.add(outside.last().ix)
        answer.addAll(toAdd.reversed())
    }
    println(answer.joinToString(" "))
}

data class Point(val ix: Int, val area: Long)