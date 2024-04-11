a = gets.chomp!
b = gets.chomp!
t = gets.chomp!

h = Hash.new
26.times do |i|
	h[a[i]] = b[i]
end

f = ""
t.chars do |c|
	if c == c.downcase
		f.insert(-1, h[c] || c)
	else
		f.insert(-1, h[c.downcase].upcase)
	end
end

puts f