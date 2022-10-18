import java.util.*
fun readln() = readLine()!!
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() }
fun readlongs() = readstrings().map { it.toLong() }
fun readdoubles() = readstrings().map { it.toDouble() }

fun main() {
    var tt=readint()
    while(tt-- > 0){
        var n=readint()
        if(n<4){
            println("-1")
            continue
        }else if(n==4){
            println("3 1 4 2")
            continue
        }else if(n==5){
            println("3 1 4 2 5")
            continue
        }
        var ans=mutableListOf<Int>()
        var a=listOf(1,4,2,6,3,5)
        var sz=0
        while(sz*6+12<=n){
            for(i in 0..5){
                ans.add(sz*6+a[i])
            }
            sz++
        }
        if(n-sz*6==6){
            for(i in 0..5){
                ans.add(sz*6+a[i])
            }
        }else if(n-sz*6==7){
            for(i in 0..5){
                ans.add(sz*6+a[i])
            }
            sz++
            ans.add(sz*6+1)
        }else if(n-sz*6==10){
            for(i in 0..5){
                ans.add(sz*6+a[i])
            }
            sz++
            var b=listOf(3,1,4,2)
            for(i in 0..3){
                ans.add(sz*6+b[i])
            }
        }else if(n-sz*6==11){
            for(i in 0..5){
                ans.add(sz*6+a[i])
            }
            sz++
            var b=listOf(3,1,4,2,5)
            for(i in 0..4){
                ans.add(sz*6+b[i])
            }
        }else if(n-sz*6==8){
            var b=listOf(1,5,2,6,3,7,4,8)
            for(i in 0..7){
                ans.add(sz*6+b[i])
            }
        }else if(n-sz*6==9){
            var b=listOf(1,3,5,9,7,4,8,6,2)
            for(i in 0..8){
                ans.add(sz*6+b[i])
            }
        }
        println(ans.joinToString(" "))
    }
}