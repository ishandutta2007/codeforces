n,b=gets.split.map &:to_i
a=gets.split.map &:to_i
t=(b+eval(a*'+')).to_f/n
if t<a.max
	p -1
else
	puts a.map{|i|t-i}*"\n"
end