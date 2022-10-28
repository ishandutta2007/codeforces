M = 10 ** 9 + 7

t = int(raw_input())

for _ in range(t):
 n = int(raw_input())
 a = [int(i) for i in raw_input().split()]

 pos = [0] * n
 for i in range(n):
  pos[a[i]] = i

 answer = 1
 (l, r) = (n, -1)
 for i in range(n):
  l = min(l, pos[i])
  r = max(r, pos[i])
  if pos[i] != l and pos[i] != r:
   answer *= r - l + 1 - i
  answer %= M

 print answer