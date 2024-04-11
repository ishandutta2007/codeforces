$stdin=File.open('input.txt')
$stdout=File.open('output.txt','w')
(n,k),a=gets.split.map(&:to_i),gets.split.map(&:to_i)
z=p a.sort[-k]
b=[]
n.times{|i|
	b<<i+1 if a[i]>=z
}
puts b.sort[0...k]*' '