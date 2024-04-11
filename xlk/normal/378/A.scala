object TEST{
	def main(args: Array[String]) {
		var a = readLine.split(' ').map(_.toInt).toList
		var z = Array(0, 0, 0)
		for (i <- 1 to 6) {
			if (Math.abs(i - a(0)) < Math.abs(i - a(1))) {
				z(0) = z(0) + 1
			} else if (Math.abs(i - a(0)) > Math.abs(i - a(1))) {
				z(2) = z(2) + 1
			} else {
				z(1) = z(1) + 1
			}
		}
		printf("%d %d %d\n", z(0), z(1), z(2))
	}
}