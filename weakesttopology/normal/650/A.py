n = int(input())

fx, fy = {}, {}
f = {}

for i in range(n):
    x, y = map(int, input().split())
    fx[x] = fx.get(x, 0) + 1
    fy[y] = fy.get(y, 0) + 1
    pt = (x, y)
    f[pt] = f.get(pt, 0) + 1

res = 0

for k, v in fx.items():
    res += v * (v - 1) // 2
for k, v in fy.items():
    res += v * (v - 1) // 2

for k, v in f.items():
    res -= v * (v - 1) // 2

print(res)