

fun main(args: Array<String>) {
    val a : MutableList<Int> = mutableListOf()
    val ans : MutableList<Int> = mutableListOf()
    val (n, k) = readLine()!!.split(' ').map(String::toLong)
    val m : List<Int> = readLine()!!.split(' ').map(String::toInt)
    for(i in m) a.add(i-1)
    
    for(i in 0..n-1) ans.add(-1)
    for(i in 0..n-1) {
        if(ans[i.toInt()] == -1) {
            val cycle : MutableList<Int> = mutableListOf()
            cycle.add(i.toInt())
            var cur : Int = a[i.toInt()]
            while(cur != i.toInt()) {
                cycle.add(cur)
                cur = a[cur]
            }
            val l : Int = cycle.size
            val shift : Int = (k % l.toLong()).toInt()
            for(j in 0..l-1) {
                val w : Int = cycle[(j+shift)%l]
                ans[w] = cycle[j]+1
            }
        }
    }
    for(i in ans) print("$i ")
}