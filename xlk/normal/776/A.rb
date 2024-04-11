a = gets.split
puts a * ' '
gets.to_i.times{
	x, y = gets.split
	a[a.index(x)] = y
	puts a * ' '
}