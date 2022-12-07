a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())
f = int(input())

ans = 0
if e > f:
    ans += e * min(a, d)
    if d > a:
        d -= a
        ans += f * min(b, c, d)
else:
    ans += f * min(b, c, d)
    if d > min(b, c):
        d -= min(b, c)
        ans += e * min(a, d)

print(ans)