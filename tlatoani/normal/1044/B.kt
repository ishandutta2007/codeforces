import java.util.*

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val adj = Array(n + 1) { mutableListOf<Int>() }
        for (j in 2..n) {
            val line = readLine()!!
            val six = line.indexOf(' ')
            val a = line.substring(0, six).toInt()
            val b = line.substring(six + 1).toInt()
            adj[a].add(b)
            adj[b].add(a)
        }
        val k1 = readLine()!!.toInt()
        var tokenizer = StringTokenizer(readLine()!!)
        val mine = IntArray(k1) { tokenizer.nextToken().toInt() }.toSet()
        val k2 = readLine()!!.toInt()
        tokenizer = StringTokenizer(readLine()!!)
        val his = IntArray(k2) { tokenizer.nextToken().toInt() }
        println("B ${his[0]}")
        val r = readLine()!!.toInt()
        val seen = BooleanArray(n + 1)
        seen[r] = true
        val q = LinkedList<Int>()
        q.add(r)
        var closest = 0
        while (q.isNotEmpty()) {
            val a = q.remove()
            if (a in mine) {
                closest = a
                break
            }
            for (b in adj[a]) {
                if (!seen[b]) {
                    seen[b] = true
                    q.add(b)
                }
            }
        }
        println("A $closest")
        val traducido = readLine()!!.toInt()
        if (traducido in his) {
            println("C $closest")
        } else {
            println("C -1")
        }
    }
}