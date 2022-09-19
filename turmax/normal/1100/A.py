n,k=map(int,input().split())
a=list(map(int,input().split()))
z=-100000
for b in range(k):
    l=a[0:len(a):1]
    v=0
    while True:
        if(v*k+b<n):
            l[v*k+b]=0
            v+=1
        else:
            break
    z=max(z,abs(l.count(1)-l.count(-1)))
print(z)