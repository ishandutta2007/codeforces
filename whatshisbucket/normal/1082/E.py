n,c=map(int,input().split())
a=list(map(int,input().split()))
cs=0
x=a.count(c)
best=[x]*5000001
curr=[x]*5000001
rec=[0]*5000001
for i in range(n):
    if a[i]==c:
        cs+=1
    else:
        curr[a[i]]=max(x,curr[a[i]]+rec[a[i]]-cs)+1
        best[a[i]]=max(best[a[i]],curr[a[i]])
        rec[a[i]]=cs
print(max(best))