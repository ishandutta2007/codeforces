p, k = map(int, input().split())

n = 0
cur = 1
ans = [0 for i in range(100)]

while True:
  tmp = p
  for i in range(n+1):
    # print("i, p: ", i, p)
    x = (p%k+k)%k
    ans[i] = x
    p = -(p-x)//k

  if p == 0 and ans[n] != 0:    
    print(n+1)
    for i in range(n+1):
      print(ans[i])
    break

  cur *= k*k
  n += 2
  p = tmp