val T = arrayOf(
    "zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
)

val O = arrayOf(
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
)

fun main() {
    val s = readLine()!!.toInt()
    if (s < O.size) {
        println(O[s])
    } else {
        println(T[s / 10] + if (s % 10 == 0) "" else "-" + O[s % 10])
    }
}