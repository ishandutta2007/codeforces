import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main(){
    var q = readInt();
    repeat(q){
        val n = readInt();
        var lo = 0; var hi = 200000;
        repeat(n){
            val (s, t, r) = readStrings()
            var k = 0;
            while (k < s.length && k < t.length && s[s.length - 1 - k] == t[t.length - 1 - k]){
                k += 1;
            }
            if (r == "1"){
                hi = min(hi, k);
            }
            else{
                lo = max(lo, k + 1);
            }
        }
        if (lo <= hi){
            println(hi - lo + 1)
            val ans = IntArray(hi - lo + 1);
            for (i in lo..hi){
                ans[i - lo] = i;
            }
            println(ans.joinToString(separator = " "));
        }
        else{
            println(0);
            println();
        }
    }
}