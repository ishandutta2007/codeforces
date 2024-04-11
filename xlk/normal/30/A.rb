a,b,n=gets.split.map &:to_i
-1000.upto(1000){|_|
	if a*_**n==b then
		p _
		exit
	end
}
print 'No solution'