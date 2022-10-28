n,m=map(int,input().split())
coords=list(map(int,input().split()))
taxis=list(map(int,input().split()))
spots=[]
riders=[]
for i in range(n+m):
    if taxis[i]==1:
        spots.append(coords[i])
    else:
        riders.append(coords[i])
spots.append(100000000000000)
a=0
for i in range(n):
    while True:
        if abs(riders[i]-spots[a])<=abs(riders[i]-spots[a+1]):
            riders[i]=a
            break
        else:
            a+=1
ans=[0]*m
for i in range(n):
    ans[riders[i]]+=1
out=""
for i in range(m):
    out+=str(ans[i])+" "
print(out[:-1])