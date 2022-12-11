x1, y1, x2, y2 = map(int, input().split())
dx = x2 - x1
dy = y2 - y1

A = (dx // 2 + 1)
B = (dy // 2 + 1)

print(A * B + (dx // 2) * ((dy + 1) // 2))