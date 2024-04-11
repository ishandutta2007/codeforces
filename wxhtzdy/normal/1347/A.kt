fun main(argv: Array<String>) {
    var tt = readLine()!!.toInt();
    while(tt>0) {
        val a = readLine()!!.split(" ").map { it.toInt() }.sorted()
        println("%d".format(a[0] + a[1]));
        tt-=1;
    }
}