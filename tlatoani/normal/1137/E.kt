import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var tokenizer = StringTokenizer(jin.readLine())
    var n = tokenizer.nextToken().toLong()
    val m = tokenizer.nextToken().toInt()
    val cars = mutableListOf<Car>()
    cars.add(Car(0, 0))
    val bs = mutableListOf<Long>()
    bs.add(0L)
    val ss = mutableListOf<Long>()
    ss.add(0L)
    fun calc(car: Car) = bs.last() - bs[car.t] + (car.x * (ss.last() - ss[car.t]))
    fun sideOfLine(a: Car, b: Car, p: Car): Long {
        val left = (b.x - a.x) * (calc(p) - calc(a))
        val right = (calc(b) - calc(a)) * (p.x - a.x)
        return left - right
    }
    val out = StringBuilder()
    for (j in 1..m) {
        tokenizer = StringTokenizer(jin.readLine())
        when (tokenizer.nextToken().toInt()) {
            1 -> {
                cars.clear()
                cars.add(Car(0, bs.size - 1))
                n += tokenizer.nextToken().toLong()
            }
            2 -> {
                if (calc(cars.last()) > 0L) {
                    cars.add(Car(n, bs.size - 1))
                    while (cars.size >= 3 && sideOfLine(cars[cars.size - 3], cars[cars.size - 2], cars.last()) <= 0L) {
                        cars.removeAt(cars.size - 2)
                    }
                }
                n += tokenizer.nextToken().toLong()
            }
            3 -> {
                bs.add(bs.last() + tokenizer.nextToken().toLong())
                ss.add(ss.last() + tokenizer.nextToken().toLong())
                while (cars.size >= 2 && calc(cars.last()) >= calc(cars[cars.size - 2])) {
                    cars.removeAt(cars.size - 1)
                }
            }
        }
        out.append(cars.last().x + 1).append(' ').appendln(calc(cars.last()))
    }
    print(out)
}

data class Car(val x: Long, val t: Int)