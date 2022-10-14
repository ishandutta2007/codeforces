x=0
for i in 0..3
x+=gets.to_i<<3-i
end
p "0101000011011011"[x].to_i