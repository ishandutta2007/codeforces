import java.util.Vector;
import kotlin.system.exitProcess;

fun main() {
    var n = readLine()!!.toInt();
    var a: IntArray = readLine()!!.split(" ").map{it.toInt();}.toIntArray();
    a.sort();
    var v1 = Vector<Int>();
    var v2 = Vector<Int>();
    var l = -1; var k = 1;
    for (u in a) {
        if (u == l) k++;
        else k = 1;
        l = u;

        if (k == 3) {
            println("NO"); exitProcess(0);
        }

        if (k == 1) v1.add(u);
        else v2.add(u);
    }

    v2.reverse();
    println("YES");
    println(v1.size);
    for (u in v1) {
        print(u); print(" ");
    }
    println();
    println(v2.size);
    for (u in v2) {
        print(u); print(" ");
    }
    println();
}