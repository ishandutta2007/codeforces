import java.util.*

fun main() {
    cases@for (c in 1..readLine()!!.toInt()) {
        val h = readLine()!!.toInt()
        val cache = mutableMapOf<Int, List<Int>>()
        var answer = 0
        var queries = 0
        fun query(a: Int): List<Int> {
            if (a !in cache) {
                if (queries == 16) {
                    answer = a
                    return listOf()
                }
                queries++
                println("? $a")
                readLine()
                val res = readLine()!!.split(" ").map { it.toInt() }
                if (res.size == 2) {
                    answer = a
                    return listOf()
                }
                cache[a] = res
            }
            return cache[a]!!
        }
        val order = mutableListOf<Int>()
        fun dfs(a: Int) {
            var a = a
            while (true) {
                order.add(a)
                var b = 0
                for (c in query(a)) {
                    if (c !in cache) {
                        b = c
                        break
                    }
                }
                if (answer != 0) {
                    return
                }
                if (b == 0) {
                    return
                }
                a = b
            }
        }
        dfs(1)
        if (answer != 0) {
            println("! $answer")
            continue@cases
        }
        order.reverse()
        order.removeAt(order.size - 1)
        dfs(1)
        if (answer != 0) {
            println("! $answer")
            continue@cases
        }
        while ((order.size / 2) < h - 4) {
            val y = order.size / 2
            while (order.size > y + 1) {
                order.removeAt(order.size - 1)
            }
            var a = 0
            for (c in query(order.last())) {
                if (c !in cache) {
                    a = c
                    break
                }
            }
            dfs(a)
            if (answer != 0) {
                println("! $answer")
                continue@cases
            }
        }
        val q = LinkedList<Int>()
        q.add(order[order.size / 2])
        while (q.isNotEmpty()) {
            val a = q.remove()
            for (b in query(a)) {
                if (b !in cache) {
                    q.add(b)
                }
            }
            if (answer != 0) {
                println("! $answer")
                continue@cases
            }
        }
    }
}