read = lambda : map(int, input().split())
n, m = read()
l = 1
r = n
for i in range(m):
    u, v = read()
    l = max(l, min(u, v))
    r = min(r, max(u, v))

print(r - l if l <= r else 0)