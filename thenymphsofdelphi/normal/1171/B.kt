import java.util.Scanner

fun main(args: Array<String>) {
   	var score = 6
    val input = Scanner(System.`in`)
    val a = input.nextInt()
    val b = input.nextInt()
    val c = input.nextInt()
    for (i in 2..999){
        if(i <= a && i+1 <= b && i+2 <= c)
        	score = score+3
        else break
    }
    println(score)
}