n,m,k=map(int,input().split())
a=[0 for i in range(m)]
kitten=0
l = 0
for i in range(n):
 s=input()
 for j in range(m):
  if s[j]=='Y':
   a[j]+=1
   if a[j]==k:
    l+=1
print(l)