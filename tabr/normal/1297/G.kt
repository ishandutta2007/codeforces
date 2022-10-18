import java.util.*
import kotlin.math.*
fun readln() = readLine()!!
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() }
fun readlongs() = readstrings().map { it.toLong() }
fun readdoubles() = readstrings().map { it.toDouble() }
fun readintarray() = ArrayList(readints())
fun readlongarray() = ArrayList(readlongs())
fun readdoublearray() = ArrayList(readdoubles())

fun main() {
    var (m,k)=readints()
    var a=IntArray(4)
    var b=listOf(2,3,5,7)
    for(i in 0..3){
        while(m%b[i]==0){
            m/=b[i]
            a[i]++
        }
    }
    if(m!=1){
        println("-1")
        return
    }
    var n=44800
    var dp = Array(n){Array(a[0]+1){Array(a[1]+1){Array(a[2]+1){IntArray(a[3]+1)}}}}
    dp[0][0][0][0][0]=1
    var c=Array(4){IntArray(10)}
    for(i in 0..3){
        for(j in 1..9){
            var t=j
            while(t%b[i]==0){
                t/=b[i]
                c[i][j]++
            }
        }
    }
    for(p in 1..n-1){
        for(q in 0..a[0]){
            for(r in 0..a[1]){
                for(s in 0..a[2]){
                    for(t in 0..a[3]){
                        for(i in 1..9){
                            var nq=q-c[0][i]
                            var nr=r-c[1][i]
                            var ns=s-c[2][i]
                            var nt=t-c[3][i]
                            if(min(min(nq,nr),min(ns,nt))<0){
                                continue
                            }
                            if(dp[p-1][nq][nr][ns][nt]==-1){
                                dp[p][q][r][s][t]=-1
                                break
                            }
                            dp[p][q][r][s][t]+=dp[p-1][nq][nr][ns][nt]
                            if(dp[p][q][r][s][t]>k){
                                dp[p][q][r][s][t]=-1
                                break
                            }
                        }
                    }
                }
            }
        }
    }
    var cur=arrayListOf(0,a[0],a[1],a[2],a[3])
    while(dp[cur[0]][cur[1]][cur[2]][cur[3]][cur[4]]!=-1 && dp[cur[0]][cur[1]][cur[2]][cur[3]][cur[4]] < k){
        k-=dp[cur[0]][cur[1]][cur[2]][cur[3]][cur[4]]
        cur[0]++
    }
    var ans=IntArray(cur[0])
    while(cur[0]>0){
        for(i in 1..9){
            var d=IntArray(4)
            for(j in 0..3){
                d[j]=cur[j+1]-c[j][i]
            }
            if(d.min()!!<0){
                continue
            }
            var t=dp[cur[0]-1][d[0]][d[1]][d[2]][d[3]]
            if(t==-1 || k<=t){
                cur[0]--
                ans[cur[0]]=i
                for(j in 1..4){
                    cur[j]=d[j-1]
                }
                break
            }
            k-=t
        }
    }
    println(ans.reversed().joinToString(""))
}