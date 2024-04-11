fun main(){
    val q = readLine()!!.toInt()
    for(i in 1..q){
        val fl = readLine()!!.split(" ").map { it.toInt() }
        val a = if(fl[0]<fl[1]) fl[0]-1 else fl[1]-1
        val b = fl[0]-a
        val c = fl[1]-a
        println("$a $b $c")
    }
}