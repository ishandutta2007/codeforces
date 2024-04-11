n=gets.to_i
a=gets.split.map &:to_i
b=gets.split.map &:to_i
z=[]
n.times{|i|
	j=i;
	j+=1 while a[i]!=b[j];
	j.downto(i+1){|k|
		b[k],b[k-1]=b[k-1],b[k]
		z<<[k,k+1]
	}
}
p z.size
z.each{|x,y|
	print "#{x} #{y}\n"
}