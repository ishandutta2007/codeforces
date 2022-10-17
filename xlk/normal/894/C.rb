n = gets.to_i
a = gets.split.map &:to_i
if a.any?{|i|i % a[0] > 0} then p -1 else puts 2 * n - 1, a * (" %d " % a[0]) end