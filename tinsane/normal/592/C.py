def gcd(a, b):
    while (b > 0):
        a, b = b, a % b
    return a

inp = [int(i) for i in input().split(' ')]
t = inp[0]
w = inp[1]
b = inp[2]
nok = w * b // gcd(w, b)
ans = t // nok * min(w, b) - 1
tmp = t % nok
ans += min(tmp + 1, min(w, b))
g = gcd(ans, t)
print(ans // g, t // g, sep='/')