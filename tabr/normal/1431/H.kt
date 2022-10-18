import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*
val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var(h,w,kk)=readints()
    var k=kk.toLong()
    var a=readlongs()
    var b=readlongs()
    a.add(1e18.toLong())
    b.add(1e18.toLong())
    var c=Array(h){LongArray(w){0L}}
    for(i in 0..h-1){
        var d=readlongs()
        c[i]=d.toLongArray()
    }
    for(i in 0..h-1){
        for(j in 0..w-1){
            if(i!=h-1){
                c[i+1][j]=max(c[i+1][j],c[i][j])
            }
            if(j!=w-1){
                c[i][j+1]=max(c[i][j+1],c[i][j])
            }
        }
    }
    var x=0
    var y=0
    var z=0L
    var ww=ArrayList<Pair<Int,Int>>()
    while(x!=h-1||y!=w-1){
        while(x!=h-1&&z>=a[x+1]){
            x++
        }
        while(y!=w-1&&z>=b[y+1]){
            y++
        }
        ww.add(Pair(x,y))
        if(x==h-1&&y==w-1){
            break
        }
        var d=min(a[x+1],b[y+1])-z
        z+=(d+c[x][y]-1)/c[x][y]*c[x][y]
    }
    // println(ww.joinToString(" "))
    var ans=1e18.toLong()
    for(p in ww){
        x=0
        y=0
        z=0L
        var cnt=0L
        while(x!=h-1||y!=w-1){
            while(x!=h-1&&z>=a[x+1]){
                x++
            }
            while(y!=w-1&&z>=b[y+1]){
                y++
            }
            if(x==h-1&&y==w-1){
                break
            }
            var e=c[x][y]
            if(p.first<=x&&p.second<=y){
                e=max(e,c[p.first][p.second]+k)
            }
            // println("${x} ${y} $e")
            var d=min(a[x+1],b[y+1])-z
            z+=(d+e-1)/e*e
            cnt+=(d+e-1)/e
        }
        // println(p)
        // println(cnt)
        ans=min(ans,cnt)
    }
    println(ans)
}

fun readln() = input.readLine()
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readstrings() = ArrayList(readln().split(" "))
fun readints() = ArrayList(readstrings().map { it.toInt() })
fun readlongs() = ArrayList(readstrings().map { it.toLong() })
fun cout(s: String) = output.appendln(s)
fun cout(s: Int) = output.appendln(s.toString())
fun cout(s: Long) = output.appendln(s.toString())
fun assert(x: Boolean) { if (!x) throw AssertionError() }