read = lambda : map(int, input().split())
def dis(x1, y1, x2, y2):
    return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5

ax, ay, bx, by, tx, ty = read()
n = int(input())
a, b = [], []
sum = 0
for i in range(n):
    x, y = read()
    dist = dis(tx, ty, x, y)
    a.append((dis(ax, ay, x, y) - dist, i))
    b.append((dis(bx, by, x, y) - dist, i))
    sum += dist * 2
a.sort()
b.sort()
if n > 1 and a[0][1] == b[0][1]:
    ans = min(a[0][0], b[0][0], a[0][0] + b[1][0], a[1][0] + b[0][0])
else:
    ans = min(a[0][0], b[0][0])
    if (n > 1) :
        ans = min(a[0][0] + b[0][0], ans)
print(ans + sum)