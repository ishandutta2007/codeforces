fun readln() = readLine()!!
fun readint() = readln().toInt() 
fun readlong() = readln().toLong() 
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() } 
fun readlongs() = readstrings().map { it.toLong() } 
fun readdoubles() = readstrings().map { it.toDouble() }

fun main(){
    var k =readint()
    while(k-- > 0){
        var s=readln()
        var t=readln()
        var i=0
        var ans="YES"
        s+='*'
        for(j in t.indices){
            if(t[j]=='-'){
                if(s[i]=='-'){
                    i++
                    continue
                }
                ans="NO"
                break
            }else{
                if(s[i]=='+'){
                    i++
                    continue
                }else if(s[i]=='-' && s[i+1]=='-'){
                    i+=2
                    continue
                }
                ans="NO"
                break;
            }
        }
        if(i+1 != s.length){
            ans="NO"
        }
        println(ans)
    }
}