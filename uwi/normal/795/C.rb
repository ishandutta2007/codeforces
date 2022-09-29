r=->{gets.split.map &:to_i}
ns=r[]
n = ns[0]
if n % 2 == 0 then
	puts "1"*(n/2)
else
	puts "7" + "1"*(n/2-1)
end