n=int(input())
j=list(map(int,input().split()))
best=0
guys=1
for i in range(n-1):
    if j[i+1]-j[i]==1:
        guys+=1
    else:
        guys=1
    if guys>best:
        best=guys
skip=False
if j[0]==1:
    for i in range(n-1):
        if i+2!=j[i+1]:
            best=max(best,i+2)
            skip=True
            break
    if not skip and n>2:
        best=n+1  
if j[-1]==1000:
    for i in range(n-1):
        if 1000-i-1!=j[-i-2]:
            best=max(best,i+2)
            skip=True
            break
    if not skip and n>2:
        best=n+1
if j==[1,2] or j==[999,1000]:
    print(1)
elif best>1:   
    print(best-2)
else:
    print(0)