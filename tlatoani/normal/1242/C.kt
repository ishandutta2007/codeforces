import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val k = jin.nextInt()
    var total = 0L
    val diffs = LongArray(k)
    val map = mutableMapOf<Long, Int>()
    val boxes = Array(k) { b ->
        val n = jin.nextInt()
        val res = mutableSetOf<Long>()
        for (j in 0 until n) {
            val a = jin.nextLong()
            map[a] = b
            res.add(a)
            total += a
            diffs[b] += a
        }
        res
    }
    total /= k.toLong()
    for (b in 0 until k) {
        diffs[b] = total - diffs[b]
    }
    val masks = mutableMapOf<Int, IntArray>()
    for (b in 0 until k) {
        for (a in boxes[b]) {
            var mask = 1 shl b
            var last = b
            var deficit = diffs[b] + a
            val placement = IntArray(k)
            var works = true
            while (true) {
                if (deficit == a) {
                    placement[last] = a.toInt()
                    break
                } else if (map.contains(deficit)) {
                    if ((mask and (1 shl map[deficit]!!)) == 0) {
                        placement[last] = deficit.toInt()
                        last = map[deficit]!!
                        mask = mask or (1 shl last)
                        deficit += diffs[last]
                    } else {
                        works = false
                        break
                    }
                } else {
                    works = false
                    break
                }
            }
            //println("b = $b, a = $a, mask = $mask, placemtn = ${placement.contentToString()}, works = $works")
            if (works && !masks.containsKey(mask)) {
                val newMap = mutableMapOf<Int, IntArray>()
                newMap[mask] = placement
                for (prevMask in masks.keys) {
                    if ((prevMask and mask) == 0 && !masks.containsKey(prevMask or mask)) {
                        val prevPlacement = masks[prevMask]!!
                        val newPlacement = IntArray(k)
                        for (b in 0 until k) {
                            newPlacement[b] = prevPlacement[b] + placement[b]
                        }
                        newMap[prevMask or mask] = newPlacement
                    }
                }
                newMap.forEach { k, v -> masks[k] = v}
            }
        }
    }
    if (masks.containsKey((1 shl k) - 1)) {
        val placement = masks[(1 shl k) - 1]!!
        val answerA = IntArray(k)
        val answerB = IntArray(k)
        println("YES")
        for (b in 0 until k) {
            val a = placement[b]
            answerA[map[a.toLong()]!!] = a
            answerB[map[a.toLong()]!!] = b
        }
        for (b in 0 until k) {
            println("${answerA[b]} ${answerB[b] + 1}")
        }
    } else {
        println("NO")
    }
}