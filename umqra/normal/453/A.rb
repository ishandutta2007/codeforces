def dice_max(n, m)
    (1..m).map { |x| 1 - (1.0 * (x - 1) / m)**n }.sum
end
m, n = gets.chomp.split.map { |x| x.to_i }
print dice_max(n, m)