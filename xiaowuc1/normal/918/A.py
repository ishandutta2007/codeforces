l = [1, 1]
while len(l) < 20:
  l.append(l[-1] + l[-2])
ret = ""
n = int(raw_input())
for i in xrange(1, n+1):
  if i in l:
    ret += 'O'
  else:
    ret += 'o'
print ret