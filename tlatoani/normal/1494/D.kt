import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val lcaSalary = arrayOf(listOf<Int>()) + Array(n) { listOf(0) + jin.readLine().split(" ").map { it.toInt() } }
    val pairs = mutableListOf<Pair<Int, Int>>()
    for (a in 1..n) {
        for (b in a + 1..n) {
            pairs.add(Pair(a, b))
        }
    }
    pairs.sortBy { (a, b) -> lcaSalary[a][b] }
    val salary = IntArray(2 * n) { if (it in 1..n) lcaSalary[it][it] else 0 }
    val parent = IntArray(2 * n)
    val currAncestor = IntArray(n + 1) { it }
    var lastID = n
    for ((a, b) in pairs) {
        if (currAncestor[a] != 0 && currAncestor[b] != 0) {
            if (salary[currAncestor[a]] == lcaSalary[a][b]) {
                parent[currAncestor[b]] = currAncestor[a]
                currAncestor[b] = 0
            } else if (salary[currAncestor[b]] == lcaSalary[a][b]) {
                parent[currAncestor[a]] = currAncestor[b]
                currAncestor[a] = 0
            } else {
                lastID++
                parent[currAncestor[a]] = lastID
                parent[currAncestor[b]] = lastID
                salary[lastID] = lcaSalary[a][b]
                currAncestor[a] = lastID
                currAncestor[b] = 0
            }
        }
    }
    println(lastID)
    println(salary.toList().subList(1, lastID + 1).joinToString(" "))
    println(lastID)
    for (a in 1 until lastID) {
        println("$a ${parent[a]}")
    }
}