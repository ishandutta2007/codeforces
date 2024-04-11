n = int(input())

x, y = [None] * n, [None]*n
for i in range(n):
    xl, yl, xh, yh = map(int, input().split())
    x[i] = (xl, xh)
    y[i] = (yl, yh)

def op(x, y):
    return (max(x[0], y[0]), min(x[1], y[1]))

inf = 10**9
prefx = [(-inf, +inf)] * n
prefy = prefx.copy()
suffx = [(-inf, +inf)] * n
suffy = suffx.copy()

for i in range(n - 1):
    prefx[i + 1] = op(prefx[i], x[i])
    prefy[i + 1] = op(prefy[i], y[i])
for i in range(n - 1, 0, -1):
    suffx[i - 1] = op(suffx[i], x[i])
    suffy[i - 1] = op(suffy[i], y[i])

for i in range(n):
    xc = op(prefx[i], suffx[i])
    yc = op(prefy[i], suffy[i])
    if xc[0] <= xc[1] and yc[0] <= yc[1]:
        print(xc[0], yc[0])
        exit()