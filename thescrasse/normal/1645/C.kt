fun main() {
    var n = readLine()!!.toInt();
    var a: Array<Int> = readLine()!!.split(" ").map{it.toInt();}.toTypedArray();
    a.sort();

    var res = 0;
    for (i in 0 .. n - 1) {
        if (i % 2 == 1) res += a[i];
        else res -= a[i];
    }
    println(res);
}