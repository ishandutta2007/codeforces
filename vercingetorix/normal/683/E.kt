

fun main(args: Array<String>) {
    val a : MutableList<Int> = mutableListOf()
    val ans : MutableList<Int> = mutableListOf()
    val (n) = readLine()!!.split(' ').map(String::toInt)
    val m : List<Int> = readLine()!!.split(' ').map(String::toInt)
    for(i in m) a.add(i)
    for(i in 1..n) ans.add(-1)
    for(i in 0..n-1) {
        var pos : Int = -1
        var num : Int = -1
        while(num < a[i]) {
            pos++
            while(ans[pos] >= 0) pos++
            num++
        }
        ans[pos] = i+1
    }

    for(i in ans) print("$i ")
}