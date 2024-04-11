n=int(input())
a=list(map(int,input().split()))
q=int(input())
changes=[0]*q
for i in range(q):
    changes[-i-1]=tuple(map(int,input().split()))
final=[-1]*n
curr=0
for guy in changes:
    if guy[0]==1:
        if final[guy[1]-1]==-1:
            final[guy[1]-1]=max(guy[2],curr)
    else:
        curr=max(curr,guy[1])
for i in range(n):
    if final[i]==-1:
        final[i]=max(curr,a[i])
final=[str(guy) for guy in final]
print(" ".join(final))