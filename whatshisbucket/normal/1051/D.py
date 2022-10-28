n,k=map(int,input().split())
same=[0]*(k+1)
diff=[0]*(k+1)
same[1]=2
if k>1:
    diff[2]=2
for i in range(n-1):
    newsame=[0]*(k+1)
    newdiff=[0]*(k+1)
    for i in range(1,k+1):
        newsame[i]=(same[i]+same[i-1]+2*diff[i])%998244353
    for i in range(2,k+1):
        newdiff[i]=(2*same[i-1]+diff[i]+diff[i-2])%998244353
    same=newsame
    diff=newdiff
print((same[-1]+diff[-1])%998244353)