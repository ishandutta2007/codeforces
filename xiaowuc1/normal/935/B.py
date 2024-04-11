n = int(raw_input())
s = raw_input()
ret = 0
x = 0
y = 0
last = 0
for xx in s:
  if xx == 'U':
    x += 1
  else:
    y += 1
  if x > y:
    if last == -1:
      ret += 1
    last = 1
  if x < y:
    if last == 1:
      ret += 1
    last = -1
print ret