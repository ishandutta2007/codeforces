
fun main(args: Array<String>) {
    val (n) = readLine()!!.split(' ').map(String::toInt)
    
    val m : MutableList<Pair<Int, String>> = mutableListOf()
    val rad : MutableList<MutableList<String>> = mutableListOf()
    for(i in 0..240) rad.add(mutableListOf())
    for (i in 0..n-1) {
        val(a,b) = readLine()!!.split(' ').map(String::toString)
        rad[b.toInt()].add(a)
    }
    for(i in 0..240) {
        for(j in rad[i]) println(j)
    }
}