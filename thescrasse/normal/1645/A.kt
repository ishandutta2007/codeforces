fun main() {
    repeat(readLine()!!.toInt()) {
        var n = readLine()!!.toInt();
        var a = readLine()!!.split(" ").map{it.toInt();};
        var f = Array(110, {0});
        for (u in a) f[u]++;

        for (i in 0 .. n - 1) {
            if (f[a[i]] == 1) println(i + 1);
        }
    }
}