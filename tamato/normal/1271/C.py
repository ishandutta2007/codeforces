import sys
input = sys.stdin.buffer.readline

N, sx, sy = map(int, input().split())
x_plus = 0
x_minus = 0
y_plus = 0
y_minus = 0
for _ in range(N):
    x, y = map(int, input().split())
    if x > sx:
        x_plus += 1
    elif x < sx:
        x_minus += 1
    if y > sy:
        y_plus += 1
    elif y < sy:
        y_minus += 1

M = max(x_plus, x_minus, y_plus, y_minus)
print(M)
if x_plus == M:
    if sx + 1 <= 10**9:
        print(sx+1, sy)
elif x_minus == M:
    if sx - 1 >= 0:
        print(sx-1, sy)
elif y_plus == M:
    if sy + 1 <= 10**9:
        print(sx, sy+1)
elif y_minus == M:
    if sy-1 >= 0:
        print(sx, sy-1)