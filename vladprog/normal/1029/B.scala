//package com.test.tasks

object HelloWorld1 extends App {
  import scala.io.StdIn._

  readInt()
  print(maxContext(readLine().split(" ").map(_.toInt).toList))

  def maxContext(diffs: List[Int]): Int = {
    def loop(diffs: List[Int], last: Int,  max: Int, cur: Int): Int = diffs match {
      case Nil => Math.max(max, cur)
      case x :: xs =>
        if (x <= last * 2) loop(xs, x, max, cur+1)
        else loop(xs, x, if (cur > max) cur else max, 1)
    }
    loop(diffs.tail, diffs.head, 1, 1)
  }

}

object HelloWorld2 extends App {
  import scala.io.StdIn._

  readInt()
  print(maxContext(readLine().split(" ").map(_.toInt).toList))

  def maxContext(diffs: List[Int]): Int = {
    def loop(diffs: List[Int], last: Int,  max: Int, cur: Int): Int = diffs match {
      case Nil => Math.max(max, cur)
      case x :: xs =>
        if (x <= last * 2) loop(xs, x, max, cur+1)
        else loop(xs, x, if (cur > max) cur else max, 1)
    }
    loop(diffs.tail, diffs.head, 1, 1)
  }

}