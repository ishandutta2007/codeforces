import kotlin.math.min

fun main() {
    val n = readLine()!!.toInt()
    val products = Array(n) {
        val (needed, forDiscount) = readLine()!!.split(" ").map { it.toLong() }
        Product(needed, forDiscount)
    }
    products.sortBy { it.forDiscount }
    var bought = 0L
    var spent = 0L
    var j = 0
    var k = products.lastIndex
    while (j <= k) {
        if (bought >= products[j].forDiscount) {
            bought += products[j].needed
            spent += products[j].needed
            j++
        } else {
            val buying = min(products[k].needed, products[j].forDiscount - bought)
            products[k].needed -= buying
            bought += buying
            spent += 2L * buying
            if (products[k].needed == 0L) {
                k--
            }
        }
    }
    println(spent)
}

data class Product(var needed: Long, val forDiscount: Long)