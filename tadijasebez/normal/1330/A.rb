t = gets.chomp.to_i
while t>0 do
    tmp = gets.chomp.split(" ")
    n = tmp[0].to_i
    k = tmp[1].to_i
    a = gets.chomp.split(" ")
    cnt = Array.new(205,0)
    for i in 0..n-1
        cnt[a[i].to_i] += 1
    end
    ans = 1
    while k>=0 do
        if cnt[ans]==0 then
            k -= 1
        end
        ans += 1
    end
    puts ans-2
    t -= 1
end