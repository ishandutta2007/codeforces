a, b = gets.split.map &:to_i
s = []
while b > a do
	s << b
	if b % 2 == 0 then
		b /= 2
	elsif b % 10 == 1 then 
		b /= 10
	else
		break
	end
end
if b == a then
	s << b
	puts 'YES'
	puts s.size
	puts (s.reverse.map &:to_s) * ' '
elsif 
	puts 'NO'
end