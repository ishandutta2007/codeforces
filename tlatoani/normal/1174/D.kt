fun main() {
    val (n, x) = readLine()!!.split(" ").map { it.toInt() }
    var e = 17
    while ((x shr e) and 1 == 0) {
        e--
    }
    val nums = mutableListOf<Int>()
    for (y in 0 until (1 shl n)) {
        if ((y shr e) and 1 == 0) {
            nums.add(y)
        }
    }
    val answer = IntArray(nums.size - 1) { nums[it] xor nums[it + 1] }
    println(answer.size)
    println(answer.joinToString(" "))
}