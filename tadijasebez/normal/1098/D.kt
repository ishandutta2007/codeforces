import java.util.*
import java.math.*
import java.security.*
 
fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts() = readLn().split(" ").map{it.toInt()}
fun readLong() = readLn().toLong()
fun readLongs() = readLn().split(" ").map{it.toLong()}
 
val out = mutableListOf<String>()
fun printLine(s: String) { out.add(s) }
fun output() { println(out.joinToString("\n")) }
 
val N = 500050
var ls = IntArray(N){0}
var rs = IntArray(N){0}
var pri = IntArray(N){0}
var vl = IntArray(N){0}
var sum = LongArray(N){0}
var bal = LongArray(N){0}
var lzy = LongArray(N){0}
var mx = LongArray(N){0}
var root = 0
var tsz = 0
val rng = SecureRandom()

fun nnd(v:Int, s:Long):Int{
    tsz++
    vl[tsz]=v
    sum[tsz]=v.toLong()
    bal[tsz]=s
    mx[tsz]=s
    pri[tsz]=rng.nextInt(1000000000)
    return tsz
}
fun pull(c:Int){ 
    mx[c] = Math.max(mx[ls[c]],Math.max(bal[c].toLong(),mx[rs[c]]))
    sum[c] = sum[ls[c]]+vl[c].toLong()+sum[rs[c]]
}
fun rot_l(c:Int):Int{
    var a = rs[c]
    var b = ls[a]
    rs[c] = b
    ls[a] = c
    pull(c)
    pull(a)
    return a
}
fun rot_r(c:Int):Int{
    var a = ls[c]
    var b = rs[a]
    ls[c] = b
    rs[a] = c
    pull(c)
    pull(a)
    return a
}
fun upd(c:Int, x:Long){
    if(c!=0){
        bal[c] += x
        lzy[c] += x
        mx[c] += x
    }
}
fun push(c:Int){
    if(lzy[c] != 0.toLong()){
        upd(ls[c],lzy[c])
        upd(rs[c],lzy[c])
        lzy[c] = 0.toLong()
    }
}
fun ins(_c:Int, v:Int, s:Long):Int{
    var c = _c
    if(c == 0)
        return nnd(v,s)
    push(c)
    if(vl[c]<=v){
        var sm = sum[ls[c]]+vl[c].toLong()
        rs[c]=ins(rs[c],v,s-2*sm)
        if(pri[rs[c]]>pri[c]){
            c = rot_l(c)
        }else{
            pull(c)
        }
    }else{
        upd(rs[c],(-2*v).toLong())
        bal[c] += (-2*v).toLong()
        ls[c]=ins(ls[c],v,s)
        if(pri[ls[c]]>pri[c]){
            c = rot_r(c)
        }else{
            pull(c)
        }
    }
    return c
}
fun dl(_c:Int):Int{
    var c = _c
    push(c)
    if(ls[c]==0){
        c = rs[c]
    }else if(rs[c]==0){
        c = ls[c]
    }else if(pri[ls[c]]>pri[rs[c]]){
        push(ls[c])
        c = rot_r(c)
        rs[c]=dl(rs[c])
        pull(c)
    }else{
        push(rs[c])
        c = rot_l(c)
        ls[c]=dl(ls[c])
        pull(c)
    }
    return c
}
fun del(_c:Int, v:Int):Int{
    //printLine("Del "+_c.toString())
    var c = _c
    push(c)
    if(vl[c] == v){
        if(ls[c]==0){
            upd(rs[c],(2*v).toLong())
            c = rs[c]
        }else if(rs[c]==0){
            c = ls[c]
        }else if(pri[ls[c]]>pri[rs[c]]){
            push(ls[c])
            c = rot_r(c)
            rs[c]=del(rs[c],v)
            pull(c)
        }else{
            push(rs[c])
            c = rot_l(c)
            upd(rs[c],(2*v).toLong())
            bal[c] += (2*v).toLong()
            ls[c]=del(ls[c],v)
            pull(c)
        }
        //upd(rs[c],(2*v).toLong())
        //c = dl(c)
    }else if(vl[c]<v){
        rs[c]=del(rs[c],v)
        pull(c)
    }else{
        upd(rs[c],(2*v).toLong())
        bal[c] += (2*v).toLong()
        ls[c]=del(ls[c],v)
        pull(c)
    }
    return c
}
fun Get(c:Int):Int{
    if(mx[c]<=0)
        return 0;
    var ans = 0
    push(c)
    if(bal[c]>0){
        ans++
    }
    ans += Get(ls[c])+Get(rs[c])
    return ans
}
var tree = ArrayList<String>()
fun P(c:Int){
    if(c!=0){
        push(c)
        P(ls[c])
        tree.add("("+vl[c].toString()+" "+bal[c].toString()+" "+lzy[c].toString()+" "+c.toString()+")")
        P(rs[c])
    }
}

fun main(){
    mx[0]=(-1e18).toLong()
    var q = readInt()
    var n = 0
    for(i in 1..q){
        var tmp = readLn().split(" ")
        var x = tmp[1].toInt()
        if(tmp[0] == "+"){
            root = ins(root,x,x.toLong())
            n++
        }else{
            root = del(root,x)
            n--
        }
        printLine((n-Get(root)).toString())
        /*if(true){
            P(root)
            printLine(tree.joinToString(" "))
            tree = ArrayList<String>()
        }*/
    }
    output()
}