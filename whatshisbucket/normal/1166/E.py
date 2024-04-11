m,n=map(int,input().split())
sets=[]
for i in range(m):
    a=list(map(int,input().split()))
    sets.append(set(a[1:]))
good=True
for i in range(m):
    for j in range(i+1,m):
        if len(sets[i]&sets[j])==0:
            good=False
if good:
    print("possible")
else:
    print("impossible")