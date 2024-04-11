l, r, a = (int(x) for x in raw_input().split())
ret = 0
while True:
  if l == 0 and a == 0:
   break
  if l:
    l -= 1
  else:
    a -= 1
  if a == 0 and r == 0:
    break
  if r:
    r -= 1
  else:
    a -= 1
  ret += 1
print 2 * ret