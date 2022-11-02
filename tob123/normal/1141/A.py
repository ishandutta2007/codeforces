[n, m] = [int(x) for x in input().split()]

flag = True
for i in range(50):
  for j in range(50):
    if n * 2**i * 3**j == m:
      print(i+j)
      flag = False

if flag:
  print(-1)