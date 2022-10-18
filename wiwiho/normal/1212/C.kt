fun main(args: Array<String>){

    val t = readLine()!!.split(" ").map{it.toInt()}

    val n = t[0]
    val k = t[1]

    val l = readLine()!!.split(" ").map{it.toInt()}.toMutableList()
    l.sort()
    if(k == 0){
        if(l[0] > 1) println(1)
        else println(-1)
        return
    }
    if(k == n || l[k - 1] != l[k]) println(l[k - 1])
    else println(-1)

}