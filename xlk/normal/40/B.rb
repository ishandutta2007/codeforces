n,m=gets.split.map &:to_i;x=gets.to_i-1
p [n,m].min>2*x ?[n+m-4*x-2,1].max: 0