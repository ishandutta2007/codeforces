import sys
a, b, c, d, e, f = (int(x) for x in raw_input().split())
if (a+b+c+d+e+f)%2:
  print "NO"
  sys.exit()
goal = (a+b+c+d+e+f)/2
can = False
can |= goal == a+b+c
can |= goal == a+b+d
can |= goal == a+b+e
can |= goal == a+b+f
can |= goal == a+c+d
can |= goal == a+c+e
can |= goal == a+c+f
can |= goal == a+d+e
can |= goal == a+d+f
can |= goal == a+e+f

print "YES" if can else "NO"