
 fun main() {
    var T = readLine()!!.toInt()
    while (T > 0) {
        val (x,y) = readLine()!!.split(" ").map { it.toInt() }
        val a = minOf(x,y)-1;
        val b = x-a;
        val c = y-a;
        print(a.toString()+' ');
        print(b.toString()+' ');
        print(c.toString()+' ');
        println()
        T--;
    }
}