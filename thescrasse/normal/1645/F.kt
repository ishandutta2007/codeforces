fun main() {
    var n = readLine()!!.toInt();
    var a: IntArray = readLine()!!.split(" ").map{it.toInt();}.toIntArray();
    a.shuffle(); a.sort();

    for (i in 0 .. n - 1) {
        if (i == 0) {
            a[i] = maxOf(1, a[i] - 1); continue;
        }
        if (a[i] - 1 > a[i - 1]) a[i]--;
        else if (a[i] > a[i - 1]) 1;
        else if (a[i] + 1 > a[i - 1]) a[i]++;
        else a[i] = a[i - 1];
    }

    var res = 1;
    for (i in 1 .. n - 1) {
        if (a[i] != a[i - 1]) res++;
    }

    println(res);
}