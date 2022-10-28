n,k=map(int,input().split())
a=list(map(int,input().split()))
sames=[]
for i in range(n-1):
    if a[i]==a[i+1]:
        sames.append(i)
sames=[-1]+sames+[n-1]
best=0
for i in range(len(sames)-1):
    best=max(best,sames[i+1]-sames[i])
print(best)