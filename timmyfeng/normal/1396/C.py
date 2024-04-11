n, r1, r2, r3, d = map(int, raw_input().split())
a = map(int, raw_input().split())

back, move = 10 ** 18, 0
for i in range(n):
  one = min(r1, r3) * a[i] + r3
  two = min(min(r1, r3) * a[i] + r1, r2) + min(r1, r2, r3)
  back, move = move + two + d, min(move + one, back + two + d, back + one + (0 if i == n - 1 else d))

print min(move, back + d) + (n - 1) * d