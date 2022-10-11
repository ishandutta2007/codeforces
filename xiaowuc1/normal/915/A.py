n, k = (int(x) for x in raw_input().split())
l = [int(x) for x in raw_input().split()]
ret = k
for x in l:
  if k%x == 0:
    ret = min(ret, k/x)
print ret