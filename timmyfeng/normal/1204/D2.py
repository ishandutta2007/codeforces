s = list(raw_input())
ones = []
for i in xrange(len(s)):
  if s[i] == '0':
    if ones:
      ones.pop()
  else:
    ones.append(i)
for i in ones:
  s[i] = '0'
print(''.join(s))