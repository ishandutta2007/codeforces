n = int(input())
for i in range(n):
 m = int(input())
 a = list(map(int, input().split()))
 x = sum(i for i in a if i <= 2048)
 if x >= 2048:
  print("YES")
 else:
  print("NO")