import kotlin.math.*


fun main(args: Array<String>) {
    val S = readLine()!!
    for(i in 0 until S.length) {
        val res = Integer.parseInt(S[i].toString())

        if(res%8==0) {
            println("YES")
            println(res)
            return;
        }
    }
    for(i in 0 until S.length) {
        for(j in (i + 1) until S.length) {
            val res = Integer.parseInt((S[i].toString() + S[j].toString()))
            if(S[i] == '0')
                continue;
            if(res%8==0) {
                println("YES")
                println(res)
                return;
            }
        }
    }

    for(i in 0 until S.length) {
        for(j in (i+1) until S.length) {
            for(k in (j + 1) until S.length) {
                if(S[i] == '0')
                    continue;
                val res = Integer.parseInt(S[i].toString() + S[j].toString() + S[k].toString())
                if(res%8==0) {
                    println("YES")
                    println(res)
                    return
                }
            }
        }
    }
    println("NO");
}