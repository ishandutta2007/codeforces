import java.io.*
import java.util.*
import kotlin.math.*

fun main(args: Array<String>) {
	val `in` = InputReader(System.`in`)
	val out = PrintWriter(System.out)
	val t = `in`.nextInt()
	for (tt in 0 until t) {
		val n = `in`.nextInt()
		val m = `in`.nextInt()
		val u = IntArray(m)
		val v = IntArray(m)
		val w = IntArray(m)
		val a = IntArray(n + 1)
		for (i in 0 until m) {
			u[i] = `in`.nextInt()
			v[i] = `in`.nextInt()
			w[i] = `in`.nextInt()
			a[u[i]] = max(a[u[i]], w[i])
			a[v[i]] = max(a[v[i]], w[i])
		}
		var ok = true
		for (i in 0 until m) {
			ok = ok and (min(a[u[i]], a[v[i]]) == w[i])
		}
		if (ok) {
			out.println("YES")
			for (i in 1..n) {
				out.print(a[i].toString() + " ")
			}
			out.println()
		} else {
			out.println("NO")
		}
	}
	out.close()
}

internal class InputReader(str: InputStream?) {
	var read: BufferedReader
	var token: StringTokenizer? = null
	operator fun next(): String {
		while (token == null || !token!!.hasMoreTokens()) {
			token = try {
				StringTokenizer(read.readLine())
			} catch (e: IOException) {
				throw RuntimeException(e)
			}
		}
		return token!!.nextToken()
	}

	fun nextInt(): Int {
		return next().toInt()
	}

	init {
		read = BufferedReader(InputStreamReader(str), 1 shl 15)
	}
}