n,a,b=gets.split.map &:to_i
c=[1]
if b==0&&a>0
	if a==n-1
		p -1
		exit
	else
		c<<1
	end
end
b.times{|_|c<<2*2**_}
a.times{c<<c.max+1}
c<<1 while c.size<n
puts c*' '