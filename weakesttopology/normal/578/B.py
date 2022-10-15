n, k, x = map(int, input().split())
a = list(map(int, input().split()))

x = x ** k

pref, suff = [0]*n, [0]*n

for i in range(n - 1):
    pref[i + 1] = a[i] | pref[i]
for i in range(n - 1, 0, -1):
    suff[i - 1] = a[i] | suff[i]

res = 0
for i in range(n):
    res = max(res, (a[i] * x) | pref[i] | suff[i])

print(res)