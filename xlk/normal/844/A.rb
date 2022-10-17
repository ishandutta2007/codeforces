s=gets.chomp.chars
k=gets.to_i
puts k > s.size ? :impossible : [0, k - s.uniq.size].max