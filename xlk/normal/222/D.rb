n,x=gets.split.map &:to_i
a=gets.split.map &:to_i
b=gets.split.map &:to_i
a.sort!;b.sort!;
z=0;n-=1;a.each{|_|
	if _+b[n]>=x then
		z+=1;n-=1;
	end
}
puts [1,z]*' '