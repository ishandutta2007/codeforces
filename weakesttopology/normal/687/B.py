import io,os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

n, k = map(int, input().split())
c = list(map(int, input().split()))

pr = []
x = k
for d in range(2, x + 1):
    if d * d > x:
        break
    if x % d == 0:
        pr.append(d)
        while x % d == 0:
            x //= d
if x > 1:
    pr.append(x)

f = {p: 0 for p in pr}
for x in c:
    for p in pr:
        e = 0
        while x % p == 0:
            x //= p
            e += 1
        f[p] = max(f[p], e)

ans = 'Yes'
for p, e in f.items():
    for j in range(e):
        if k % p == 0:
            k //= p
    if k % p == 0:
        ans = 'No'
print(ans)