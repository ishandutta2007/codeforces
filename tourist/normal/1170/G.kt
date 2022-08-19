fun main(args: Array<String>) {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val from = IntArray(m)
    val to = IntArray(m)
    for (i in 0 until m) {
        val (foo, bar) = readLine()!!.split(" ").map { it.toInt() }
        from[i] = foo - 1
        to[i] = bar - 1
    }
    val g = Array<MutableList<Int>>(n, { i -> mutableListOf() })
    for (i in 0 until m) {
        g[from[i]].add(i)
        g[to[i]].add(i)
    }
    val deg = IntArray(n)
    for (i in 0 until m) {
        deg[from[i]]++
        deg[to[i]]++
    }
    for (i in 0 until n) {
        if (deg[i] % 2 == 1) {
            println("NO")
            return
        }
    }
    println("YES")
    val used = BooleanArray(m)
    val ptr = IntArray(n)
    val res = IntArray(m)
    var write_ptr = m
    var stack_ptr = 0
    for (root in 0 until n) {
        var v = root
        while (true) {
            var found = false
            while (ptr[v] < g[v].size) {
                var id = g[v][ptr[v]++]
                if (used[id]) {
                    continue
                }
                used[id] = true
                res[stack_ptr++] = id
                v = v xor from[id] xor to[id]
                found = true
                break
            }
            if (!found) {
                if (stack_ptr == 0) {
                    break;
                }
                var id = res[--stack_ptr]
                res[--write_ptr] = id
                v = v xor from[id] xor to[id]
            }
        }
    }
    val cycles: MutableList<MutableList<Int>> = mutableListOf()
    var seen = IntArray(4 * n)
    for (i in 0 until 4 * n) {
        seen[i] = -1
    }
    var now = 0
    seen[0] = 0
    stack_ptr = 0
    for (i in 0 until m) {
        now = now xor from[res[i]] xor to[res[i]]
        res[stack_ptr++] = res[i]
        if (seen[now] != -1) {
            var ver = from[res[seen[now]]]
            var cycle: MutableList<Int> = mutableListOf(ver + 1)
            val start = seen[now]
            var ok = 1
            for (j in start until stack_ptr) {
                if (ver != from[res[j]] && ver != to[res[j]]) {
                    ok = 0
                }
                ver = ver xor from[res[j]] xor to[res[j]]
                cycle.add(ver + 1)
                now = now xor from[res[j]] xor to[res[j]]
                seen[now] = -1
            }
            if (ok == 0) {
                ver = to[res[start]]
                cycle = mutableListOf(ver + 1)
                for (j in start until stack_ptr) {
                    ver = ver xor from[res[j]] xor to[res[j]]
                    cycle.add(ver + 1)
                }
            }
            stack_ptr -= cycle.size - 1
            cycles.add(cycle)
        }
        seen[now] = stack_ptr
    }
    println(cycles.size)
    var s = Array<String>(cycles.size, { i -> "" })
    for (i in 0 until cycles.size) {
        s[i] = cycles[i].size.toString() + " " + cycles[i].joinToString(" ")
    }
    println(s.joinToString("\n"))
}