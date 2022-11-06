
t=int(input())
for nbt in range(t):
    n,k=[int(i) for i in input().split()]
    a=[int(i) for i in input().split()]
    nbc=len(set(a))-1
    if k==1:
        if nbc:
            print(-1)
        else:
            print(1)
    else:
        print(1+max(0,(nbc-1)//(k-1)))