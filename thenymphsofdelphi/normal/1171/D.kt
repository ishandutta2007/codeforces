fun main(args : Array<String>) {
    val (x1, y1, z1) = readLine()!!.split(' ')
    val (g1, p1, b1) = readLine()!!.split(' ')
    var x = x1.toInt()
    var y = y1.toInt()
    var z = z1.toInt()
    var g = g1.toInt()
    var p = p1.toInt()
    var b = b1.toInt()
    var d = 0
    var m = 0

    if(g>=x){
        d = g + p - x
        if(d>=y){
            m = g+p+b-x-y
            if(m>=z){
                println("YES")
            }
            else{
                println("NO")
            }
        }
        else{
            println("NO")
        }

    }
    else{
        println("NO")
    }

}