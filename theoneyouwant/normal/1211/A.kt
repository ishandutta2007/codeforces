import kotlin.math.*
import java.util.*
import kotlin.collections.ArrayList
 
//private fun readLn() = readLine()!!
//private fun readInt() = readLn().toInt()
//private fun readStrings() = readLn().split(" ")
//private fun readInts() = readStrings().map { it.toInt() }
//private fun Boolean.toInt() = if (this) 1 else 0
 
 
fun main(args : Array<String>) {


    val cin = Scanner(System.`in`)
    val n = cin.nextInt()
 
    val lst = ArrayList<Int>()
    val newlst = ArrayList<Int>()
    for (i in 1..n) {
        lst.add(cin.nextInt())
        newlst.add(lst[i-1])
    }
    
    lst.sort()
    var mi = lst[0]
    var ma = lst[n-1]
    var f = -1
    for(i in 1..n){
        if(lst[i-1] != lst[0]){
            if(lst[i-1] != lst[n-1]){
                f = lst[i-1]
            }
        }
    }
    if(f == -1){
        mi = -1
        ma = -1
    }
    
    if(f != -1){
        for(i in 1..n){
            if(newlst[i-1] == ma){
                ma = i
                break
            }
        }
        for(i in 1..n){
            if(newlst[i-1] == f){
                f = i
                break
            }
        }
        for(i in 1..n){
            if(newlst[i-1] == mi){
                mi = i
                break
            }
        }
    }
    
    print(mi)
    print(" ")
    print(f)
    print(" ")
    print(ma)
}