fun main() {
    var n = readLine()!!.toInt();
    var s = readLine()!!.toString();

    var i = 0; var d = 1;
    while (i < n) {
        print(s[i]); i += d; d++;
    }
    println();
}