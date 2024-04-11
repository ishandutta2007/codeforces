n=int(input())
for _ in range(n):
    s=input()
    l=[]
    a=b=0
    for c in s:
        if c==a:
            b+=1
        else:
            if b%2>0 and not a in l:
                l+=[a]
            a=c
            b=1
    if b%2>0 and not a in l:
        l+=[a]
    print(*sorted(l),sep='')