n,m,k=map(int,input().split())
a=list(map(int,input().split()))
a.reverse()
curr=0
boxesused=0
index=0
done=False
while boxesused<m:
    if index==n:
        done=True
        print(n)
        break
    j=a[index]
    if j+curr<=k:
        curr+=j
        index+=1
    else:
        boxesused+=1
        curr=j
        index+=1
if not done:
    print(index-1)