fun main(vararg args: String) {
    val t = readLine()!!.toInt()
    for (i in t downTo 1) {
      val line = readLine()!!.toCharArray()
      if (line.distinct().count() == 1) {
          println("-1")
          continue
      }
      if (isPalindrom(line)) {
          line.sort()
      }
      println(line)
    }
}

fun isPalindrom(word: CharArray): Boolean {
  var i1 = 0
  var i2 = word.size - 1
  while (i2 > i1)
  {
    if (word[i1] != word[i2])
    {
      return false
    }
    ++i1
    --i2
  }
  return true
}