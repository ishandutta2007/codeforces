t=int(raw_input())
for i in range(t):
    n=int(raw_input())
    res=0
    while n:
        if n%2:
            res+=1
        n>>=1
    print 2**res