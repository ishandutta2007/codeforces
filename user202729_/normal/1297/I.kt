// n log^2 n is not fast enough? Really?...
import java.io.PrintWriter
import java.util.StringTokenizer
import java.util.TreeSet

data class SegmentTree(
        val maximum_:IntArray, // Below lazy of this node
        val lazy:IntArray // value set to, -1 if none. Applied from leaf to root
) {
    constructor(len: Int): this(IntArray(len*2){0}, IntArray(len*2){-1})

    fun maximum(node: Int):Int{
        return if(lazy[node]>=0) lazy[node] else maximum_[node]
    }

    fun push(node: Int){
        assert(node!=0)
        if(lazy[node]>=0){
            maximum_[node]=lazy[node]
            lazy[node*2]=lazy[node]
            lazy[node*2+1]=lazy[node]
            lazy[node]=-1
        }
    }

    fun compute(index: Int): Int{
        val node=index+lazy.size/2
        val bit=(0..32).first{ (node shr it)==1 }
        (bit downTo 1).forEach{ push(node shr it) }
        return maximum(node)
    }

    fun update(left: Int, right: Int, value: Int){
        var nodeLeft=left+lazy.size/2
        var nodeRight=right+lazy.size/2
        compute(left)
        compute(right-1)
        while(nodeLeft<nodeRight){
            if(0!=(nodeLeft and 1)) lazy[nodeLeft++]=value
            if(0!=(nodeRight and 1)) lazy[--nodeRight]=value
            nodeLeft=nodeLeft shr 1
            nodeRight=nodeRight shr 1
        }

        listOf(left, right-1).forEach outer@{
            val node=it+lazy.size/2
            (1..32).asSequence().map{node shr it}.forEach{
                if(it==0) return@outer
                maximum_[it]=maxOf(maximum(it*2), maximum(it*2+1))
            }
        }
    }
}


data class SegmentTree2(
        val maximum: IntArray,
        val value: Array<TreeSet<Int>>
) {
    constructor(len: Int): this(
            IntArray(len*2),
            Array(len){TreeSet<Int>()}
    )

    fun add_(height_index: Pair<Int, Int>){
        val added=value[height_index.second].add(height_index.first)
        assert(added)
        val node=height_index.second+maximum.size/2
        maximum[node]=value[height_index.second].last()!!
        (1..32).asSequence().map{node shr it}.forEach{
            if(it==0) return
            maximum[it]=maxOf(maximum[it*2], maximum[it*2+1])
        }
    }

    fun remove_(height_index: Pair<Int, Int>){
        val removed=value[height_index.second].remove(height_index.first)
        assert(removed)
        val node=height_index.second+maximum.size/2
        value[height_index.second].run{
            maximum[node]=if(isEmpty()) 0 else last()!!
        }
        (1..32).asSequence().map{node shr it}.forEach{
            if(it==0) return
            maximum[it]=maxOf(maximum[it*2], maximum[it*2+1])
        }
    }
}

fun PrintWriter.solve() {
    val numBlock=readInt()
    val len=readInt()

    //val gap=IntArray(len+1){0}
    val gap=SegmentTree(len+1)

    val blocks=SegmentTree2(len);


    // it's possible to do this in O(n log n) instead of O(n log^2 n)
    // compare by second element is unnecessary, but Kotlin doesn't have multiset data type

    var count=0
    repeat(numBlock){
        val left=readInt()-1
        val right=readInt()
        val height=1+maxOf(gap.compute(left), gap.compute(right))
        //(left+1 until right).forEach{gap[it]=height}
        if(left+1<right)
            gap.update(left+1, right, height)

        run{ // remove relevant nodes
            val process={node: Int ->
                while(true){
                    val item=blocks.maximum[node]
                    if(item<height) break

                    var node1=node
                    while(node1<blocks.value.size){
                        node1*=2
                        if(blocks.maximum[node1]<height) ++node1
                        assert(blocks.maximum[node1]>=height)
                    }

                    blocks.remove_(Pair(blocks.maximum[node1], node1-blocks.maximum.size/2))
                    --count
                }
            }
            var nodeLeft=left+blocks.value.size
            var nodeRight=right+blocks.value.size
            while(nodeLeft<nodeRight){
                if(0!=(nodeLeft and 1)) process(nodeLeft++)
                if(0!=(nodeRight and 1)) process(--nodeRight)
                nodeLeft=nodeLeft shr 1
                nodeRight=nodeRight shr 1
            }
        }

        /*
        (left until right).forEach{index->
            while(true){
                val item=blocks[index].pollLast()
                if(item==null) break
                if(item.first<height){
                    blocks[index].add(item)
                    break
                }
                --count
            }
        }
        blocks[left].add(Pair(height, left))
        */

        blocks.add_(Pair(height, left))
        ++count
        println(count)
    }
}

@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out

@JvmField val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
    while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }

@JvmField val _writer = PrintWriter(OUTPUT, false)
inline fun output(block: PrintWriter.() -> Unit) { _writer.apply(block).flush() }

fun main() { _writer.solve(); _writer.flush() }