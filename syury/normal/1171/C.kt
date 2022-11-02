import java.util.*

fun main(){
    var T = readLine()!!.toInt();
    var cnt = IntArray ( 27 );
    for(i in 0..26){cnt[i] = 0;}
    while(T != 0){
        --T;
        val s = readLine();
        val len = s!!.length;
        for(i in 0..len-1){
            ++cnt[s[i]-'a'];
        }
        var ans = "";
        for(i in 0..26){
            while(cnt[i] != 0){
                ans += 'a' + i;
                --cnt[i];
            }
        }
        if(ans[0] != ans[ans.length - 1]){println(ans);}
        else{println(-1);}
    }
}