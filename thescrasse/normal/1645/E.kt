import java.util.Stack;
import kotlin.system.exitProcess;

fun main() {
    var (n, k) = readLine()!!.split(" ").map{it.toInt();};
    var st = Stack<Int>();
    for (i in 0 .. 30) {
        if (((n shr i) and 1) == 1) st.push(1 shl i);
    }

    if (n < k || st.size > k) {
        println("NO"); exitProcess(0);
    }

    var ones = 0; k -= st.size;
    for (i in 1 .. k) {
        while (st.peek() == 1) {
            st.pop(); ones++;
        }
        var x = st.peek();
        st.pop(); st.push(x / 2); st.push(x / 2);
    }

    println("YES");
    for (i in 1 .. ones) print("1 ");
    for (u in st) print("$u ");
    println();
}