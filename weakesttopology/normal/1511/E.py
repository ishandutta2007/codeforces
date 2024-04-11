import sys
input = sys.stdin.readline

n, m = map(int, input().split())
s = [input() for i in range(n)]

mod = 998244353
inv = 499122177

w, res = 0, 0

for i in range(n):
    even, odd = 0, 1
    for j in range(m):
        if s[i][j] == '*':
            even, odd = 0, 1
        else:
            res += even * inv
            even, odd = odd * inv, even * inv + inv
            even %= mod
            odd %= mod
            res %= mod
            w += 1

for j in range(m):
    even, odd = 0, 1
    for i in range(n):
        if s[i][j] == '*':
            even, odd = 0, 1
        else:
            res += even * inv
            even, odd = odd * inv, even * inv + inv
            even %= mod
            odd %= mod
            res %= mod

for i in range(w):
    res = 2 * res % mod

print(res)