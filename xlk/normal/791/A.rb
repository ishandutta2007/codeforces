a, b = gets.split.map &:to_i
9.times{|i|if a*3**i>b*2**i then p i; break end}