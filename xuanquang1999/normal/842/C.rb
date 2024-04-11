n = gets.to_i
a = gets.split.map &:to_i
g = Array.new(n) { [] }

(n-1).times do
    u, v = gets.split.map &:to_i
    u, v = u-1, v-1
    g[u] << v
    g[v] << u
end

def GCD(a, b)
    return (b == 0) ? a : GCD(b, a%b)
end

dp = Array.new(n) { Array.new(2) { [] } }
dp[0] = [[a[0]], [0]]
par = [-1]*n

q = [0]
until q.empty?
    u = q.shift
    g[u].each do |v|
        next if v == par[u]
        par[v] = u
        q.unshift(v)
        dp[u][0].each do |x|
            dp[v][0] << GCD(x, a[v]);
            dp[v][1] << x
        end
        dp[u][1].each do |x|
            dp[v][1] << GCD(x, a[v])
        end
        for i in 0..1 do
            dp[v][i].uniq!
        end
    end
end

print a[0]
for u in 1...n do
    print " #{dp[u][1].max}"
end