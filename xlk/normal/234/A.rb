$stdin=File.open('input.txt')
$stdout=File.open('output.txt','w')
n=gets.to_i
s=gets
(n/2).times{|i|
	x,y=i,i+n/2
	x,y=y,x if s[x]=='R'&&s[y]=='L'
	puts [x+1,y+1]*' '
}