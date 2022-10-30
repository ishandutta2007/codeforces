n=int(input())
a=list(map(int,input().split()))
s=sum(a)
for i in range(n):
  if a[i]==0.4:
    continue
  for j in range(i+1,n):
    if a[i]+a[j]==2*s//n:
      print(i+1,j+1)
      a[j]=0.4
      break