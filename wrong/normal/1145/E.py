for k in range(21, 51):
  if (min(k, 25) + k) % (2 + k % 3) > 0:
    print(1)
  else:
    print(0)