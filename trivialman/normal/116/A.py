n = int(input())
tot = 0
maxn = 0
for i in range(n):
    a, b = map(int, input().split())
    tot = tot+b-a
    maxn = max(maxn, tot)
print(maxn)