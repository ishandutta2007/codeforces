import java.util.*
import kotlin.math.max

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val cities = Array(n) { i -> City((i + 1).toLong(), jin.nextLong()) }
    cities.sort()
    println(max(1L, (cities.last().selfies - 1L) * n.toLong() + cities.last().ix))
}

data class City(val ix: Long, val selfies: Long): Comparable<City> {
    override fun compareTo(other: City) = compareValuesBy(this, other, { it.selfies }, { it.ix })
}