def f(s):
  r = 0
  while s:
    r += s % 10
    s /= 10
  return r

n = int(raw_input())
a = 1
while True:
  if f(a) == 10:
    n -= 1
    if n == 0:
      print a
      break
  a += 1