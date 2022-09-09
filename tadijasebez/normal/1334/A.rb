t = gets.chomp.to_i
while t>0 do
    n = gets.chomp.to_i
    las_a = 0
    las_b = 0
    ok = true
    for i in 1..n do
        tmp = gets.chomp.split(" ")
        a = tmp[0].to_i
        b = tmp[1].to_i
        if b-las_b>a-las_a or b<las_b or a<las_a then
            ok = false
        end
        las_a = a
        las_b = b
    end
    if ok then
        puts "YES"
    else
        puts "NO"
    end
    t -= 1
end