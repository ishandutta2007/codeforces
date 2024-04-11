n=int(input())
p=list(map(int,input().split()))
p=[guy-1 for guy in p]
locs=[0]*n
for i in range(n):
    locs[p[i]]=i
out=[]
for j in range(n//2):
    if locs[j]<n//2 and locs[j]!=j:
        out.append((n,locs[j]+1))
        a,b=locs[j],p[-1]
        p[a],p[-1],locs[j],locs[b]=b,j,n-1,a
        out.append((n,j+1))
        a=p[j]
        p[n-1],p[j],locs[j],locs[a]=a,j,j,n-1
    elif locs[j]!=j:
        out.append((j+1,locs[j]+1))
        a,b=p[j],locs[j]
        p[j],p[b],locs[j],locs[a]=j,a,j,b
    if locs[j+n//2]>=n//2 and locs[j+n//2]!=j+n//2:
        out.append((locs[j+n//2]+1,1))
        out.append((1,j+n//2+1))
        out.append((locs[j+n//2]+1,1))
        a,b=p[j+n//2],locs[j+n//2]
        p[j+n//2],p[b],locs[j+n//2],locs[a]=j+n//2,a,j+n//2,b
    elif locs[j+n//2]!=j+n//2:
        out.append((locs[j+n//2]+1,n))
        out.append((n,1))
        out.append((1,j+n//2+1))
        out.append((n,1))
        out.append((locs[j+n//2]+1,n))
        a,b=p[j+n//2],locs[j+n//2]
        p[j+n//2],p[b],locs[j+n//2],locs[a]=j+n//2,a,j+n//2,b
print(len(out))
for guy in out:
    print(guy[0],guy[1])