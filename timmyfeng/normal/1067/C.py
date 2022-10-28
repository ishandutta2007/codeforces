n = input()

for i in range(n):
  if i % 3 == 2:
    print i / 3 * 2 + 1, 3
  else:
    print i / 3 * 2 + i % 3, 0