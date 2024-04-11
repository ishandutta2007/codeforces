n = gets.split.map(&:to_i)[0];
a = []
(1..n).each { |i| a << gets.split.map(&:to_i) }
(1..n).each { |k|
	(1..n).each { |i|
		(1..n).each { |j|
			a[i-1][j-1] = [a[i-1][k-1] + a[k-1][j-1], a[i-1][j-1]].min
		}
	}
}
ans = 0
(1..n).each { |i|
	(1..n).each { |j|
		ans = [ans, a[i-1][j-1]].max
	}
}
puts ans