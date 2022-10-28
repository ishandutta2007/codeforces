t = input()
for tt in range(t):
  n, k = map(int, raw_input().split())
  a = map(int, raw_input().split())
  l, r = min(a), max(a)
  print(l + k if r - l <= 2 * k else -1)