n=gets.to_i
p n-1
c=[0]*100020
z=[]
1.upto(n-1){|i|
	x,y=gets.split.map &:to_i
	print "2 "+$_
	if c[x]==0
		c[x]=i
	else
		z<<[i,c[x]]*' '
	end
	if c[y]==0
		c[y]=i
	else
		z<<[i,c[y]]*' '
	end
}
puts z*"\n"