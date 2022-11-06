t=int(input())
for nbt in range(t):
    d,k=[int(i) for i in input().split()]
    tt=1<<20
    mi=0
    while tt:
        if ((mi+tt)*(mi+tt)*k*k*2<=d*d):
            mi+=tt
        tt>>=1
    if (mi*k*k*mi + ((mi+1)*k)**2) <= d*d:
        print("Ashish")
    else:
        print("Utkarsh")