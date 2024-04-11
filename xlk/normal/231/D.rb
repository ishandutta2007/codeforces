require "scanf"
I =->{gets.split.map &:to_i}
RD =->{gets.to_i}

x, y, z = I[]; x1, y1, z1 = I[]; a = I[]
res = 0
res += a[0] if y < 0
res += a[1] if y > y1
res += a[2] if z < 0
res += a[3] if z > z1
res += a[4] if x < 0
res += a[5] if x > x1

puts res