import kotlin.system.exitProcess;

fun main() {
    val maxn = 200010;
    val gig = 200005;

    fun cmp() = Comparator<Pair<Int, Int>>{a, b ->
        when {
            (a.first < b.first) -> -1;
            (a.first > b.first) -> 1;
            (a.second < b.second) -> -1;
            (a.second > b.second) -> 1;
            else -> 0;
        }
    };

    var fn = ArrayList<Pair<Int, Int>>();
    for (i in 1 .. maxn) fn.add(Pair(0, 0));

    fun upd(p: Int, x: Pair<Int, Int>) {
        var p = p;
        while (p < maxn) {
            fn[p] = arrayListOf<Pair<Int, Int>>(fn[p], x).maxWithOrNull(cmp())!!;
            p += p.takeLowestOneBit();
        }
    }

    fun pm(p: Int): Pair<Int, Int> {
        var p = p; var r = Pair(0, 0);
        while (p > 0) {
            r = arrayListOf<Pair<Int, Int>>(r, fn[p]).maxWithOrNull(cmp())!!;
            p -= p.takeLowestOneBit();
        }
        return Pair(r.first + 1, r.second);
    }

    var n = readLine()!!.toInt();
    var a = arrayListOf<Int>(gig);
    a.addAll(readLine()!!.split(" ").map{it.toInt() + 1;});
    a.add(gig);

    var dp = ArrayList<Pair<Int, Int>>();
    for (i in 1 .. maxn) dp.add(Pair(0, 0));
    for (i in 1 .. n + 1) {
        dp[i] = pm(a[i] - 1); upd(a[i], Pair(dp[i].first, i));
    }

    var lis = ArrayList<Int>();
    for (i in 1 .. maxn) lis.add(0);
    var i = n + 1;
    while (i != 0) {
        lis[i] = 1; i = dp[i].second;
    }
    var lis_st = ArrayList(lis);

    var k = gig; var flag = 1;

    fun adjust(ty: Int, d: Int) {
        if (d == 0) {
            k = gig * (1 - 2 * ty); flag = 1;
            for (i in 1 .. n) {
                if (lis[i] == ty && (1 - 2 * ty) * (a[i] - k) >= 0) {
                    // println("adjust $i");
                    lis[i] = 1 - ty; flag = 0; break;
                }
                if (lis[i] == ty) k = a[i];
            }
        } else {
            k = -gig * (1 - 2 * ty); flag = 1;
            for (i in n downTo 1) {
                if (lis[i] == ty && (1 - 2 * ty) * (a[i] - k) <= 0) {
                    // println("adjust $i");
                    lis[i] = 1 - ty; flag = 0; break;
                }
                if (lis[i] == ty) k = a[i];
            }
        }
    }

    fun found() {
        println("YES");
        for (i in 1 .. n) {
            print(1 - lis[i]); print(" ");
        }
        println(); exitProcess(0);
    }

    for (mk in 0 .. 7) {
        lis = ArrayList(lis_st);
        adjust(0, (mk shr 0) and 1);
        adjust(1, (mk shr 1) and 1);
        adjust(0, (mk shr 2) and 1);
        if (flag == 1) {
            adjust(1, 0);
            if (flag == 1) found();
        }
    }
    println("NO");
}