import java.io.*
import java.util.*

fun main(args: Array<String>) {
	val `in` = InputReader(System.`in`)
	val out = PrintWriter(System.out)
	val n = `in`.nextInt()
	val m = `in`.nextInt()
	val q = `in`.nextInt()
	var trie = Trie()
	for (i in 0 until n) {
		var cur: Trie? = trie
		for (c in `in`.next().toCharArray()) {
			if (cur!!.to[c - 'a'] == null) {
				cur.to[c - 'a'] = Trie()
			}
			cur = cur.to[c - 'a']
		}
	}
	val todo: Array<ArrayList<Int>?> = arrayOfNulls(m)
	val queries = arrayOfNulls<String>(q)
	val ans = IntArray(q)
	for (i in 0 until m) {
		todo[i] = ArrayList()
	}
	for (i in 0 until q) {
		queries[i] = `in`.next()
		todo[0]?.add(i)
	}
	for (i in 0 until m) {
		for (j in todo[i]!!) {
			var cur: Trie? = trie
			var k = i
			while (k < m && cur!!.to[queries[j]!![k] - 'a'] != null) {
				cur = cur.to[queries[j]!![k++] - 'a']
			}
			if (k == i) {
				ans[j] = -1
			} else if (k < m) {
				todo[k]?.add(j)
				++ans[j]
			}
		}
		val prv = trie
		trie = Trie()
		for (j in 0..25) {
			if (prv.to[j] != null) {
				trie.merge(prv.to[j])
			}
		}
	}
	for (i in ans) {
		out.println(i)
	}
	out.close()
}

internal class Trie {
	var to: Array<Trie?>
	fun merge(oth: Trie?) {
		for (i in 0..25) {
			if (to[i] == null) {
				to[i] = oth!!.to[i]
			} else if (oth!!.to[i] != null) {
				to[i]!!.merge(oth.to[i])
			}
		}
	}

	init {
		to = arrayOfNulls(26)
	}
}

internal class InputReader(str: InputStream?) {
	var reader: BufferedReader
	var tokenizer: StringTokenizer? = null
	operator fun next(): String {
		while (tokenizer == null || !tokenizer!!.hasMoreTokens()) {
			tokenizer = try {
				StringTokenizer(reader.readLine())
			} catch (e: IOException) {
				throw RuntimeException(e)
			}
		}
		return tokenizer!!.nextToken()
	}

	fun nextInt(): Int {
		return next().toInt()
	}

	fun nextLong(): Long {
		return next().toLong()
	}

	init {
		reader = BufferedReader(InputStreamReader(str), 1 shl 15)
	}
}