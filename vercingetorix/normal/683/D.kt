fun main(args: Array<String>) {
    val (q) = readLine()!!.split(' ').map(String::toInt)
    
   for(i in 1..q) {
        val(m,n,p) = readLine()!!.split(' ').map(String::toInt)
        var x : Int = 0
        for(m1 in 1..m) {
            val n1:Int = p/m1
            if(((n1*m1)==p) && (n1<=n)) {
                x=1
            }
        }
        if (x==1) println("Yes")
        else println("No")
    
   }
}