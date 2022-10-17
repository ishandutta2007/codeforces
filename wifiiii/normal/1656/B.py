t = int(input())
for i in range(t):
  n, k = map(int, input().split(' '))
  a = list(map(int, input().split(' ')))
  a.sort()
  mp = dict()
  ok = 0
  for j in a:
    if mp.get(j - k):
      ok = 1
    mp[j] = 1
  if ok:
    print("YES")
  else:
    print("NO")