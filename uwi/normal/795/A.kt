fun main(args: Array<String>) {
    val (n, c1, c2) = readLine()!!.split(" ").map(String::toInt)
    val a = readLine()!!
    var one = 0
    for(e in a){
    	one += e.toInt()-48
    }
    val zero = n - one
    var ret = 999999999999999999
    for(i in 1..one){
    	val v = i.toLong()*c1+(n/i-1).toLong()*(n/i-1)*(i-n%i)*c2+(n/i).toLong()*(n/i)*(n%i)*c2
    	ret = if(v < ret){
    		v
    		}else{
    		ret
    		}
    }
    println("${ret}")
}