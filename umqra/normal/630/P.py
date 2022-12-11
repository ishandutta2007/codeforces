import math
n, r = map(int, input().split())

X = 2 * r * math.sin(math.pi / n)
Y = X * math.sin(math.pi * (n - 3) / (2 * n)) / math.sin(3 * math.pi / n)

S1 = 1 / 2 * Y * Y * math.sin(3 * math.pi / n)
S2 = r * r * (math.pi / n - 1 / 2 * math.sin(2 * math.pi / n))
ans = math.pi * r * r - n * (S1 + S2)
print(ans)