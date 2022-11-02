n = int(input())
a = list(map(int, input().split()))
a += a
ans = 360
for i in range(n):
  cur = 0
  j = i
  while cur < 180:
    cur += a[j]
    j += 1
  ans = min(ans, 2*cur - 360)
print(ans)