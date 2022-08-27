

fun main(args: Array<String>) {
    val (a, b) = readLine()!!.split('.').map(String::toString)
    val (n, pp) = b.split('(') 
    val (p) = pp.split(')')
    var d : Int= 9
    var l = 0
    if(n.length > 0) l = n.toInt()
    for(i in 1..p.length-1) {
        d = d*10+9
    }
    var c =1 
    var v = p.toInt()
    for(i in 1..n.length) c*=10
    
    var A = l*d+v
    var B = c*d
    val div : List<Int> = listOf(2,3,5,7,11,13,37,41,73,101,137,239,271,4649)
    
    for(x in div){
    while(A%x==0 && B%x==0) {
        A/=x
        B/=x
    }
    }
    print("$A/$B")
    
}