N = int(input())
P = list(map(int, input().split()))
mod = 998244353

p = 0
q = 1
for i in range(N):
    p, q = (100 * (p+q)) % mod, (P[i] * q) % mod

print((p * pow(q, mod-2, mod))%mod)