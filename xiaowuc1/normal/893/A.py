import sys

n = int(raw_input())
playing = {1, 2}
for _ in xrange(n):
  curr = int(raw_input())
  if curr not in playing:
    print "NO"
    sys.exit()
  other = 1
  while other in playing:
    other += 1
  playing = {other, curr}
print "YES"