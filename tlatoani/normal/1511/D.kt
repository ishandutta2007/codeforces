fun main() {
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }
    val adj = Array(k) { BooleanArray(k) { true } }
    val circuit = mutableListOf<Int>()
    fun recur(a: Int) {
        for (b in 0 until k) {
            if (adj[a][b]) {
                adj[a][b] = false
                recur(b)
            }
        }
        circuit.add(a)
    }
    recur(0)
    circuit.removeAt(0)
    println(String(CharArray(n) { 'a' + circuit[it % circuit.size] }))
}