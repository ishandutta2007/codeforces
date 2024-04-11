# your code goes here
r = gets.strip.split(/\s+/).map(&:to_i)
t = r[0]
if t % 2 == 1
	puts '7' + ('1' * ((t - 3) / 2))
else
	puts '1' * (t / 2)
end