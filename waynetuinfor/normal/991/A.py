a, b, c, n = map(int, input().split())
n -= 1

if c > a or c > b: print(-1)
elif a + b - c > n: print(-1)
else: print(n - (a + b - c) + 1)