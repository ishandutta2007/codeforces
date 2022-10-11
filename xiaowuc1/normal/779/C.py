n, k = (int(x) for x in raw_input().split())
l1 = [int(x) for x in raw_input().split()]
l2 = [int(x) for x in raw_input().split()]
delta = [(l1[i] - l2[i], i) for i in xrange(n)]
delta = sorted(delta, key=lambda x: x[0])
ret = 0
i = 0
while i < n:
  idx = delta[i][1]
  if i <= k-1:
    ret += l1[idx]
  else:
    ret += min(l1[idx], l2[idx])
  i += 1
print ret