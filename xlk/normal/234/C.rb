$stdin=File.open('input.txt')
$stdout=File.open('output.txt','w')
n=gets.to_i
a=gets.split.map &:to_i
x,y=[0],[0]
n.times{|i|
	x<<x[-1]+[1,1,0][a[i]<=>0]
	y<<y[-1]+[1,0,1][a[i]<=>0]
}
p [*1...n].map{|i|x[i]+y[n]-y[i]}.min