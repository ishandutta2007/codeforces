import java.util.*
import kotlin.system.exitProcess

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun exit() : Nothing = exitProcess(0)

inline fun <T : Comparable<T> > min(x : T, y : T): T{
    if(x < y){return x;}
    else{return y;}
}

inline fun <T : Comparable<T> > max(x : T, y : T): T{
    if(x > y){return x;}
    else{return y;}
}


fun main(){
    var mp = HashMap<String, Int>();
    mp["void"] = 0;
    mp["errtype"] = -1;
    var n = readInt();
    while(n != 0){
        --n;
        val ss = readStrings();
        if(ss[0] == "typedef"){
            var i = 0;
            var j = ss[1].length - 1;
            while(i < ss[1].length && ss[1][i] == '&'){++i;}
            while(j >= 0 && ss[1][j] == '*'){--j;}
            if(i > j){mp[ss[2]] = -1; continue;}
            val s = ss[1].substring(i, j + 1);
            var d = 0;
            if(!mp.containsKey(s)){
                mp[ss[2]] = -1;
                continue;
            }
            d = mp[s]!!;
            if(d != -1){
                d += ss[1].length - 1 - j;
                d -= i;
                if(d < -1){d = -1;}
            }
            mp[ss[2]] = d;
        }
        else{
            var i = 0;
            var j = ss[1].length - 1;
            while(i < ss[1].length && ss[1][i] == '&'){++i;}
            while(j >= 0 && ss[1][j] == '*'){--j;}
            if(i > j){println("errtype"); continue;}
            val s = ss[1].substring(i, j + 1);
            if(!mp.containsKey(s)){
                println("errtype"); continue;
            }
            var d = 0;
            d = mp[s]!!;
            if(d != -1){
                d += ss[1].length - 1 - j;
                d -= i;
            }
            if(d < 0){println("errtype");}
            else{
                var ans = "void";
                for(k in 0..d-1){ans += "*";}
                println(ans);
            }
        }
    }
}