n,m,k=map(int,input().split())
b=list(map(int,input().split()))
diffs=[]
for i in range(n-1):
    diffs.append(b[i+1]-b[i])
diffs.sort()
print(k+sum(diffs[:n-k]))