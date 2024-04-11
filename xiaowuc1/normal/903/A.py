can = dict()
for a in xrange(34):
  for b in xrange(34):
    can[3*a+7*b] = True
n = int(raw_input())
for _ in xrange(n):
  print "YES" if int(raw_input()) in can else "NO"