n, m = (int(x) for x in raw_input().split())
curr = 0
for _ in xrange(n):
  a, b = (int(x) for x in raw_input().split())
  if curr >= a:
    curr = max(curr, b)
print "YES" if curr == m else "NO"