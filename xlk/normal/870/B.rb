n, k = gets.split.map &:to_i
a = gets.split.map &:to_i
p [a.min, [a[0], a[-1]].max, a.max][[k, 3].min - 1]