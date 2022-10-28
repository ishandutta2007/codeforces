n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
ainds=[None]*n
binds=[None]*n
for i in range(n):
    if a[i]>0:
        ainds[a[i]-1]=i
    if b[i]>0:
        binds[b[i]-1]=i
if binds[0] is not None:
    if b[binds[0]:]==[i+1 for i in range(n-binds[0])]:
        good=True
        for i in range(n-binds[0],n):
            if binds[i] is not None:
                if binds[i]>i-n+binds[0]-1:
                    good=False
        if good:
            print(binds[0])
        else:
            print(binds[0]+n+1)
    else:
        extra=0
        for i in range(n):
            if binds[i] is not None:
                extra=max(extra,binds[i]-binds[0]-i)
        print(binds[0]+1+n+extra)
else:
    extra=0
    for i in range(n):
        if binds[i] is not None:
            extra=max(extra,binds[i]-i+1)
    print(n+extra)