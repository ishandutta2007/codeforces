    import java.util.*
    import java.io.*
     
    val MOD = 998244353
     
    fun main()
    {
    	Thread(null, Main(), "whatever", 1 shl 28).start()
    }
     
    class Main : Runnable {
     
    	override fun run()
    	{
    		val inputStream = System.`in`
    		val outputStream = System.out
    		val `in` = InputReader(inputStream)
    		val out = PrintWriter(outputStream)
    		val solver = TaskD()
    		var test = 1
    		test = `in`.nextInt()
    		for (t in 1..test)
    		{
    			solver.solve(t, `in`, out)
    		}
    		out.close()
    	}
     
    	internal class TaskD
    	{
    		fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
    			val INF = 4000000000000000000L
    			val dx = intArrayOf(-1, 1, 0, 0)
    			val dy = intArrayOf(0, 0, -1, 1)
     
    			var n = `in`.nextInt()
     
    			if (n <= 3)
    			{
    				out.println(-1)
    				return
    			}
     
    			var p = ArrayList<Int>()
    			var k = 0
    			while (k+4 <= n)
    			{
    				p.add(k+2)
    				p.add(k+4)
    				p.add(k+1)
    				p.add(k+3)
    				k += 4
    			}
    			if (n%4 == 1)
    			{
    				p.add(n)
    			}
    			else if (n%4 == 2)
    			{
    				var back = p.removeAt(p.size-1)
    				p.add(n-1)
    				p.add(back)
    				p.add(n)
    			}
    			else if (n%4 == 3)
    			{
    				var back = p.removeAt(p.size-1)
    				p.add(n-2)
    				p.add(n)
    				p.add(back)
    				p.add(n-1)
    			}
    			out.println(p.joinToString(" "))
    		}
     
    	}
     
    	internal class InputReader(stream: InputStream) {
    		var reader: BufferedReader
    		var tokenizer: StringTokenizer? = null
     
    		init {
    			reader = BufferedReader(InputStreamReader(stream), 32768)
    			tokenizer = null
    		}
     
    		operator fun next(): String {
    			while (tokenizer == null || !tokenizer!!.hasMoreTokens()) {
    				try {
    					tokenizer = StringTokenizer(reader.readLine())
    				} catch (e: IOException) {
    					throw RuntimeException(e)
    				}
     
    			}
    			return tokenizer!!.nextToken()
    		}
     
    		fun nextInt(): Int {
    			return Integer.parseInt(next())
    		}
     
    		fun nextLong(): Long {
    		    return next().toLong()
    		}
     
    	}
    }
     
    fun gcd(a: Long, b: Long): Long = if (b == 0L) a else gcd(b, a%b)
     
    fun power(a: Long, b: Long, p: Long): Long
    {
    	if (b == 0L) return 1L
    	var t = power(a, b/2, p)
    	t = t*t%p
    	if (b%2 == 1L) t = t*a%p
    	return t
    }