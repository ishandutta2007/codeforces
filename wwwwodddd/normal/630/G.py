n = input()
def C(x, y):
 z = 1
 for i in range(y):
  z = z * (x - i) / (i + 1)
 return z
print C(n + 4, 5) * C(n + 2, 3)