import java.util.*
import kotlin.math.*

fun rs()=readLine()!!
fun ri()=rs().toInt()
fun rl()=rs().toLong()
fun rd()=rs().toDouble()
fun ris()=rs().split(" ").map{it.toInt()}
fun rls()=rs().split(" ").map{it.toLong()}
fun rds()=rs().split(" ").map{it.toDouble()}

val out=mutableListOf<String>()
fun pln(s:String){out.add(s)}
fun pln(i:Int)=pln(i.toString())
fun pln(l:Long)=pln(l.toString())
fun pln(d:Double,precision:Int=12)=pln(("%."+precision.toString()+"f").format(d))
fun pln(a:IntArray)=pln(a.joinToString(" "))
fun pln(a:LongArray)=pln(a.joinToString(" "))
fun<T> pln(a:Array<T>)=pln(a.joinToString(" "))
fun<T> pln(a:ArrayList<T>)=pln(a.joinToString(" "))
fun output(){println(out.joinToString("\n"))}

fun main(){
    var (n,m)=ris()
    m++
    val a=Array<IntArray>(n+1){IntArray(0)}
    val b=Array<IntArray>(n+1){IntArray(0)}
    val IDS=Array(m+1){IntArray(1){0} }
    val SZ=Array(m+1){0}
    val LEN=Array(m+1){0}
    val BIT=Array(m+1){LongArray(0)}
    var l=m
    while(l>0){
        if(SZ[l]==IDS[l].size){
            val tmp=IntArray(SZ[l]*2)
            for(z in 0 until IDS[l].size){
                tmp[z]=IDS[l][z]
            }
            IDS[l]=tmp
        }
        IDS[l][SZ[l]++]=m
        l-=l and -l
    }
    for(i in 1..n){
        val k=ri()
        a[i]=ris().toIntArray()
        b[i]=ris().toIntArray()
        for(j in 0 until k){
            b[i][j]++
            var l=b[i][j]
            while(l>0){
                if(SZ[l]==IDS[l].size){
                    val tmp=IntArray(SZ[l]*2)
                    for(z in 0 until IDS[l].size){
                        tmp[z]=IDS[l][z]
                    }
                    IDS[l]=tmp
                }
                IDS[l][SZ[l]++]=(b[i][j]+i)
                l-=l and -l
            }
        }
    }
    val inf=1000000000000000000L
    for(i in 1..m)if(SZ[i]!=0){
        IDS[i]=IDS[i].sliceArray(0 until SZ[i])
        IDS[i].sort()
        var len=1
        for(j in 1 until SZ[i]){
            if(IDS[i][j]!=IDS[i][len-1]){
                IDS[i][len]=IDS[i][j]
                len++
            }
        }
        LEN[i]=len
        BIT[i]=LongArray(len+1){-inf}
        //println("len:${LEN[i]} : ${IDS[i].toIntArray().joinToString(" ")}")
    }
    //for(i in 1..m)println("len:${LEN[i]} : ${IDS[i].toIntArray().joinToString(" ")}")
    fun Find(i:Int,y:Int):Int{
        if(LEN[i]==0 || y<IDS[i][0])return 0
        var top=LEN[i]-1
        var bot=0
        while(top>bot){
            var mid=(top+bot+1) shr 1
            if(IDS[i][mid]<=y){
                bot=mid
            }else top=mid-1
        }
        return bot+1
    }
    fun Get(x:Int,y:Int):Long{
        //println("Get x:$x y:$y")
        var ans=-inf
        var i=x
        while(i<=m){
            var j=Find(i,y)
            while(j>0){
                ans=max(ans,BIT[i][j])
                j-=j and -j
            }
            i+=i and -i
        }
        return ans
    }
    fun Add(x:Int,y:Int,v:Long){
        //println("Add x:$x y:$y v:$v")
        var i=x
        while(i>0){
            var j=Find(i,y)
            //println("for i:$i y:$y j=$j")
            while(j<=LEN[i]){
                BIT[i][j]=max(BIT[i][j],v)
                j+=j and -j
            }
            i-=i and -i
        }
    }
    Add(m,m,0L)
    //println(":D")
    var ans=0L
    for(i in 1..n){
        for(j in 0 until a[i].size){
            var now=Get(b[i][j],b[i][j]+i-1)+a[i][j]
            ans=max(ans,now)
            Add(b[i][j],b[i][j]+i,now)
        }
    }
    pln(ans)
    output()
}