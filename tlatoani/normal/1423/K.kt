import java.io.*
import java.util.*
import kotlin.math.*

fun main(){
	val f = BufferedReader(InputStreamReader(System.`in`))

	val MAX = 1000005

	//sieve
	val prime = BooleanArray(MAX+1){true}

	var p = 2
	while(p*p <= MAX){
		if(prime[p]){
			for(i in p*p..MAX step p){
				prime[i] = false
			}
		}

		p++
	}

	val primes = HashSet<Int>()
	val primessq = HashSet<Int>()

	for(k in 2..MAX){
		if(prime[k]){
			primes.add(k)
			if(k < 1005) primessq.add(k*k)
		}
	}



	val array = IntArray(MAX){0}
	array[1] = 1
	array[2] = 2
	array[3] = 3

	for(k in 4 until MAX){
		if(primes.contains(k)){
			array[k] = array[k-1]+1
		} else if(primessq.contains(k)){
			array[k] = array[k-1]-1
		} else {
			array[k] = array[k-1]
		}
	}

	val n = f.readLine().toInt()
	val input = f.readLine().split(" ").map{it.toInt()}
	val sb = StringBuilder()
	for(i in input) sb.appendln(array[i])
	println(sb)


}