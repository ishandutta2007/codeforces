n, x = gets.split.map &:to_i
puts gets.split.map(&:to_i).inject(:+)+n==x+1?:YES:'NO'