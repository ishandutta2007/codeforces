a = input()
while True:
  b, c = a, 0
  while b > 0:
    c += b % 10
    b /= 10
  if c % 4 == 0:
    break
  a += 1
print a