t=input()
 
for _ in range(t):
 n=input()
 a=[-1]+[int(i)-1 for i in raw_input().split()]+[-1]

 dp=[-1]*(n+2)
 dp[0]=0

 for i in range(0,n+1):
  if dp[i]==-1:
   continue
 
  occ=[0]*n
  mx=0
  for j in range(i+1,n+2):
   if 2*mx<=j-i-1 and (j-i-1)%2==0 and (a[i]==-1 or a[j]==-1 or a[i]==a[j]):
     dp[j]=max(dp[j],dp[i]+1)
   if a[j]!=-1:
    occ[a[j]]+=1
    mx=max(mx,occ[a[j]])

 print dp[n+1]-1