n,m=gets.split.map &:to_i
(p [n,m].min+1).times{|i|puts [n-i,i]*' '}