import java.util.*
import kotlin.math.max

fun main() {
    val s = readLine()!! + " "
    val t = readLine()!! + " "
    val l = s.length + t.length + max(s.length, t.length)
    val DUMMY = Node(-1, -1, -1)
    val prev = Array(s.length) { Array(t.length) { Array(l + 1) { DUMMY } } }
    val charas = Array(s.length) { Array(t.length) { CharArray(l + 1) { ' ' } } }
    val q = LinkedList<Int>()
    var a = 0
    var b = 0
    var y = 0
    fun add(da: Int, db: Int, dy: Int) {
        if (charas[a + da][b + db][y + dy] == ' ') {
            //println("\tadding ${a + da} ${b + db} ${y + dy}")
            prev[a + da][b + db][y + dy] = Node(a, b, y)
            charas[a + da][b + db][y + dy] = when (dy) {
                1 -> '('
                -1 -> ')'
                else -> '!'
            }
            q.add(a + da)
            q.add(b + db)
            q.add(y + dy)
        }
    }
    add(0, 0, 0)
    while (true) {
        a = q.remove()
        b = q.remove()
        y = q.remove()
        if (y > l / 2) {
            continue
        }
        //println("$a $b $y")
        if (a == s.length - 1 && b == t.length - 1 && y == 0) {
            val builder = StringBuilder()
            while (charas[a][b][y] != '!') {
                builder.append(charas[a][b][y])
                val node = prev[a][b][y]
                a = node.a
                b = node.b
                y = node.y
            }
            println(builder.reverse())
            return
        }
        if (s[a] == '(') {
            if (t[b] == '(') {
                add(1, 1, 1)
            } else {
                add(1, 0, 1)
            }
        } else {
            if (t[b] == '(') {
                add(0, 1, 1)
            } else {
                add(0, 0, 1)
            }
        }
        if (y > 0) {
            if (s[a] == ')') {
                if (t[b] == ')') {
                    add(1, 1, -1)
                } else {
                    add(1, 0, -1)
                }
            } else {
                if (t[b] == ')') {
                    add(0, 1, -1)
                } else {
                    add(0, 0, -1)
                }
            }
        }
    }
}

data class Node(val a: Int, val b: Int, val y: Int)