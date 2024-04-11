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
    var(n,m,k)=readints()
    var x=IntArray(m)    
    var y=IntArray(m)   
    var g=Array<MutableList<Int>>(n){mutableListOf()} 
    k--
    var end=IntArray(n)
    for(i in 0..n-1){
        end[i]=i
    }
    for(i in 0..m-1){
        var(a,b)=readints()
        a--
        b--
        x[i]=a
        y[i]=b
        g[x[i]].add(y[i])
        g[y[i]].add(x[i])
        end[x[i]] = end[y[i]].also { end[y[i]] = end[x[i]] }
    }
    var inf=1000000000
    var ans=IntArray(n){inf}
    var st:Int
    for(i in 0..n-1){
        if(end[i]==k){
            st=i
            ans[st]=0
            break
        }
    }
    var p=IntArray(n)
    for(i in 0..n-1){
        p[end[i]]=i
    }
    for(i in 0..m-1){
        p[x[i]] = p[y[i]].also { p[y[i]] = p[x[i]] }
        if(ans[p[x[i]]]==ans[p[y[i]]]){
            continue
        }
        if(ans[p[x[i]]] > ans[p[y[i]]]){
            ans[p[x[i]]]=minOf(ans[p[x[i]]],ans[p[y[i]]]+1)
        }else{
            ans[p[y[i]]]=minOf(ans[p[y[i]]],ans[p[x[i]]]+1)
        }
    }
    for(i in 0..n-1){
        if(ans[i]==inf){
            ans[i]=-1
        }
    }
    // var que=IntArray(n+2)
    // que[0]=st
    // var top=0
    // var bot=1
    // var cnt=0
    // while(top<bot){
    //     cnt++
    //     var nbot=bot
    //     for(i in top..bot-1){
    //         for(j in g[que[i]]){
    //             if(ans[j]==-1){
    //                 ans[j]=cnt
    //                 que[nbot]=j
    //                 nbot++
    //             }
    //         }
    //     }
    //     top=bot
    //     bot=nbot
    // }
    println(ans.joinToString(" "))
}