t = int(input())
for tt in range(t):
 n = int(input())
 arr2 = list(map(int, input().split()))
 m = 0
 for i in range(n):
  arr = [x for x in arr2]
  s = 0
  x = arr[i]
  for j in range(n):
   if j != i:
    while arr[j] % 2 == 0:
     x *= 2
     arr[j] //= 2
    s += arr[j]
  m = max(m, x+s)
 print(m)