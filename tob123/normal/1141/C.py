n = int(input())
q = [int(x) for x in input().split()]

a = [0]
last = 0
m = 0
mx = 0
allNum = {0}
for x in q:
  last += x
  a.append(last)
  m = min(m, last)
  mx = max(mx, last)
  allNum.add(last)

if mx-m+1 != n or len(allNum) != n:
  print(-1)
else:
  a = [str(x-m+1) for x in a]
  print(" ".join(a))