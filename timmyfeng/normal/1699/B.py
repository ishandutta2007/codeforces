t = int(raw_input())

for test_case in range(t):
 n, m = [int(i) for i in raw_input().split()]
 answer = [[((i + 1) // 2 + (j + 1) // 2) % 2 for j in range(m)] for i in range(n)]
 for i in answer:
  print ' '.join([str(j) for j in i])