import java.util.*
import java.math.*
 
fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts()  = readLn().split(" ").map{it.toInt()}
fun readLong() = readLn().toLong()
fun readLongs()  = readLn().split(" ").map{it.toLong()}
 
fun main(){
	var t = readInt()
	for(tt in 1..t){
	    var (n, l, r) = readLongs()
	    var sz = 2*n-2
	    l--
	    r--
	    var out = IntArray((r-l+1).toInt()){0}
	    var k = 0
	    for(i in 1..n){
	        if(l>=sz){
	            l-=sz
	            r-=sz
	        }else{
	            if(r>=0){
	                for(j in 0..sz-1){
	                    if(r>=0 && l<=0){
	                        var x = i
	                        if(j%2==1.toLong())
	                            x=(j+1)/2+i
	                        out[k] = x.toInt()
	                        k++
	                    }
	                    l--
	                    r--
	                }
	            }
	        }
	        sz-=2
	    }
	    for(i in 1..1){
	        if(l<=0 && r>=0){
	            out[k] = i
	            k++
	        }
	        l--
	        r--
	    }
	    println(out.joinToString(" "))
	}
}