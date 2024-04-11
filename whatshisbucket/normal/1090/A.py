n=int(input())
comps=[]
sizes=[]
large=[]
for i in range(n):
    a=list(map(int,input().split()))
    sizes.append(a[0])
    comps.append(a[1:])
big=0
for i in range(n):
    a=max(comps[i])
    large.append(a)
    big=max(big,a)
inc=0
for i in range(n):
    inc+=sizes[i]*(big-large[i])
print(inc)