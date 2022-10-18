import java.util.*

fun main(args: Array<String>){
    val scan = Scanner(System.`in`)

    var y = scan.nextInt()
    var b = scan.nextInt()
    var r = scan.nextInt()

    b -= 1;
    r -= 2;

    println(Math.min(y, Math.min(b, r)) * 3 + 3)

}