n = int(input())
a = [int(x) for x in input().split()]

res = {}

for i in range(n):
  sm = 0
  for j in range(i, n):
    sm += a[j]
    if sm in res:
      res[sm].append((i, j))
    else:
      res[sm] = [(i, j)]

best = 0
bestI = -1
for key in res:
  r = -1
  cnt = 0
  for (a,b) in sorted(res[key]):
    if a > r:
      cnt += 1
      r = b
    elif b < r:
      r = b
  if cnt > best:
    best = cnt
    bestI = key

x = []
r = -1
for (a, b) in sorted(res[bestI]):
  if a > r:
    x.append(str(a+1) + " " + str(b+1))
    r = b
  elif b < r:
    r = b
    x.pop()
    x.append(str(a+1) + " " + str(b+1))
  
print(best)
print("\n".join(x))