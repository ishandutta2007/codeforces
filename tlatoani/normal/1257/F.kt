import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val bitAmt = IntArray(1 shl 15)
    for (mask in 1 until bitAmt.size) {
        bitAmt[mask] = bitAmt[mask - (mask and -mask)] + 1
    }
    val AND = (1 shl 15) - 1
    val array = IntArray(n) { jin.nextInt() }
    val map = mutableMapOf<ArrayThing, Int>()
    for (mask in 0 until bitAmt.size) {
        var hash = 0
        val ds = IntArray(n) { j ->
            val d = bitAmt[mask xor (array[j] and AND)] - bitAmt[mask xor (array[0] and AND)]
            hash *= 37
            hash += d
            d
        }
        map[ArrayThing(ds, hash)] = mask
    }
    for (mask in 0 until bitAmt.size) {
        var hash = 0
        val ds = IntArray(n) { j ->
            val d = bitAmt[mask xor ((array[0] shr 15) and AND)] - bitAmt[mask xor ((array[j] shr 15) and AND)]
            hash *= 37
            hash += d
            d
        }
        if (map.containsKey(ArrayThing(ds, hash))) {
            println((mask shl 15) + map[ArrayThing(ds, hash)]!!)
            return
        }
    }
    println(-1)
}

class ArrayThing(val ds: IntArray, val hash: Int) {
    override fun hashCode() = hash
    override fun equals(other: Any?) = other is ArrayThing && ds.contentEquals(other.ds)
}