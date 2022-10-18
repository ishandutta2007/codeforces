R, D = gets.split.map &:to_i
n = gets.to_i
EPS = 1e-9

cnt = 0
n.times do
    x, y, r = gets.split.map &:to_i
    d = (x**2 + y**2)**0.5
    # puts("#{R} #{D} #{d} #{r} #{R-D-EPS} #{r-d} #{r+d} #{R+EPS}")
    cnt += 1 if R-D-EPS < d-r && d+r < R+EPS 
end

puts cnt