import java.util.*

fun main(args: Array<String>){

    val scan = Scanner(System.`in`)

    var n = scan.nextInt()
    var k = scan.nextInt()

    while(k-- > 0){
        if(n % 10 > 0) n--
        else n /= 10
    }

    println(n)

}