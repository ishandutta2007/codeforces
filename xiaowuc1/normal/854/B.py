n, k = (int(x) for x in raw_input().split())
if n == k:
  print "0 0"
elif k == 0:
  print "0 0"
elif k <= n/3:
  print "1 {}".format(2*k)
else:
  print "1 {}".format(n-k)