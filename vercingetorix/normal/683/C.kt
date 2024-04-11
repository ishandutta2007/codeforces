

fun main(args: Array<String>) {
    val a : MutableList<Int> = mutableListOf()
    val b : MutableList<Int> = mutableListOf()
    val c : MutableList<Int> = mutableListOf()
    val m1 : List<Int> = readLine()!!.split(' ').map(String::toInt)
    val m2 : List<Int> = readLine()!!.split(' ').map(String::toInt)
    for(i in 1..m1[0]) a.add(m1[i])
    for(i in 1..m2[0]) b.add(m2[i])
    for(i in 1..m1[0]) if(m1[i] !in b) c.add(m1[i])
    for(i in 1..m2[0]) if(m2[i] !in a) c.add(m2[i])
    print(c.lastIndex+1)
    for(i in c) print(" $i")
}