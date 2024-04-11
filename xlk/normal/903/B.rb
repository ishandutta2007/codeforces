h,a,c=gets.split.map &:to_i
g,b=gets.split.map &:to_i
k=(g+a-1)/a
n=[(b*(k-1)-h)/(c-b)+1,0].max
puts n+k,[:HEAL]*n,[:STRIKE]*k