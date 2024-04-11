n,k=map(int,raw_input().split())
a=[reduce(lambda x,y:256*x+y,map(int,raw_input().split('.'))) for _ in range(n)]
for i in range(4):
    b=[255]*i+[0]*(4-i)
    for q in reversed(range(9)):
        b[i]=256-2**q
        if ((i==0)and(b[i]==0)):continue
        e=reduce(lambda x,y:256*x+y,b)
        if (len(set([a[w]&e for w in range(n)]))==k):
            print ".".join(map(str,b))
            exit(0)
print -1