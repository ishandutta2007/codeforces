n,s,k=map(int,input().split())
r=list(map(int,input().split()))
s-=1
c=input()
best=[[0 for i in range(n)] for j in range(k+1)]
for i in range(1,k+1):
    for j in range(n):
        if i<=r[j]:
            best[i][j]=abs(j-s)
        else:
            good=float("inf")
            for l in range(n):
                if c[j]!=c[l] and r[j]>r[l]:
                    good=min(good,best[i-r[j]][l]+abs(j-l))
            best[i][j]=good
if min(best[-1])==float('inf'):
    print(-1)
else:
    print(min(best[-1]))