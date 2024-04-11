
t=int(input())
for nbt in range(t):
    n=[int(i) for i in input().split()][0]
    a=[int(i) for i in input().split()]
    b=[int(i) for i in input().split()]
    c=[int(i) for i in input().split()]
    r=[None]*n

    for i in range(0,n,2):
        r[i]=a[i]
    if (r[0]==r[-1]):
        r[-1]=b[-1]
    
    for i in range(1,n,2):
        for z in (a,b,c):
            if (r[i-1]!=z[i] and r[(i+1)%n]!=z[i]):
                r[i]=z[i]
    
    print(*r)