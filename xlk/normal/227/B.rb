n=gets.to_i
a=gets.split.map &:to_i
p=[0]*(n+1)
n.times{|i|p[a[i]]=i}
z=0
m=gets.to_i
gets.split.map(&:to_i).each{|i|z+=p[i]}
puts [z+m,m*n-z]*' '