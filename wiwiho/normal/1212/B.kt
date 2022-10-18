import java.util.*

fun main(args: Array<String>){

    val scan = Scanner(System.`in`)

    val n = scan.nextInt()
    val s = scan.next()

    val map = mutableMapOf<String, Int>()

    for(i in 0..(n - 2)){
        map.put("${s[i]}${s[i + 1]}", Optional.ofNullable(map.get("${s[i]}${s[i + 1]}")).orElse(0) + 1)
    }

    var ans = 0
    var anss = ""
    for(e in map.entries){
        if(e.value > ans){
            ans = e.value
            anss = e.key
        }
    }

    println(anss)

}