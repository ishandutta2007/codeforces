import java.util.*
 
fun main() {
    var n = readLine()!!.toInt();
    while(n != 0){
    	--n;
    	val x = readLine()!!.toInt();
    	if(x == 2 || x == 3){
    		println(1);
    	}
    	else{
    		println(x/2);
    	}
    }
}