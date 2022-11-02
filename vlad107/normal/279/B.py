R=lambda:map(int,raw_input().split())
n,t=R()
a=[0]+R()
for i in range(n):a[i+1]+=a[i]
j,ans=0,0
for i in range(n+1):
    while ((j<n)and(a[j+1]-a[i]<=t)):j+=1
    ans=max(ans,j-i)
print ans