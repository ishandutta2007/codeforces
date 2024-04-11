import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.*
val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = readint()
    while (tt-- > 0) {
        var s=readln()
        var ans=""
        var t=IntArray(26)
        var ok=true
        ans+=s[0]
        t[s[0]-'a']=1
        var pos=0
        for(i in 1..s.length-1){
            var k=s[i]-'a'
            if(pos==0){
                if(t[k]==1){
                    pos++
                    if(ans[pos]!=s[i]){
                        ok=false
                        break
                    }
                }else{
                    ans=s[i]+ans
                    t[k]=1
                }
            }else if(pos==ans.length-1){
                if(t[k]==1){
                    pos--
                    if(ans[pos]!=s[i]){
                        ok=false
                        break
                    }
                }else{
                    pos++
                    ans+=s[i]
                    t[k]=1
                }
            }else{
                if(ans[pos+1]==s[i]){
                    pos++
                }else if(ans[pos-1]==s[i]){
                    pos--
                }else{
                    ok=false
                    break
                }
            }
        }
        for(i in 0..25){
            if(t[i]==0){
                ans+='a'+i
            }
        }
        if(ok){
            cout("YES")
            cout(ans)
        }else{
            cout("NO")
        }
    }
    print(output)
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