fun main() {
    var n = readLine()!!.toInt();
    var s = readLine()!!.toString();
    var t = readLine()!!.toString();

    var a = arrayListOf<Int>();
    for (i in n - 1 downTo 0) a.add(s[i].toInt() + t[i].toInt());
    a.add(0);

    for (i in 0 .. n - 1) {
        if (a[i] > 'a'.toInt() + 'z'.toInt()) {
            a[i] -= 26; a[i + 1]++;
        }
    }

    for (i in n downTo 0) {
        if (a[i] % 2 == 1) a[i - 1] += 26;
        a[i] /= 2;
        if (i != n) print(a[i].toChar());
    }
    println();
}