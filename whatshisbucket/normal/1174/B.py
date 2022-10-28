n=int(input())
a=list(map(int,input().split()))
c,d,ind=False,False,0
while ((not c) or (not d)) and ind<n:
    if a[ind]%2==0:
        d=True
    else:
        c=True
    ind+=1
if c and d:
    print(*sorted(a))
else:
    print(*a)