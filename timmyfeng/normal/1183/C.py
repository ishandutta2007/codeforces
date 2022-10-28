t = input()
for tt in xrange(t):
  k, n, a, b = map(int, raw_input().split())
  print(min(n, (k - n * b - 1) / (a - b)) if n * b < k else -1)