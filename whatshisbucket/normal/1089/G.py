t=int(input())
for u in range(t):
    k=int(input())
    a=list(map(int,input().split()))
    per=a.count(1)
    breaks=[]
    b=a+a
    curr=1
    ind=b.index(1)+1
    for i in range(7):
        if b[ind]==0:
            curr+=1
            ind+=1
        else:
            breaks.append(curr)
            curr=1
            ind+=1
    z=k%per
    if z==0:
        print(7*(k//per)-max(breaks)+1)
    elif z==1:
        print(7*(k//per)+1)
    else:
        brea=breaks+breaks
        sums=[sum(brea[:z-1])]
        for i in range(per-1):
            sums.append(sums[-1]+brea[z+i-1]-brea[i])
        print(7*(k//per)+1+min(sums))