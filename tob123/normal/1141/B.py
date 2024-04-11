n = int(input())
a = [int(x) for x in input().split()]
a[n:] = a
cnt = 0
best = 0
for x in a:
  if x:
    cnt += 1
    best = max(best, cnt)
  else:
    cnt = 0

print(best)