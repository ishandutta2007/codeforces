from sys import stdout

n=int(input())

a=[[(1<<(i+j-1)) if (j%2) else 0 for j in range(n)] for i in range(n)]

for i in range(n):
    print(*a[i])
stdout.flush()


q=int(input())

for qs in range(q):
    k=int(input())
    res=[[1,1]]
    ci=0
    cj=0
    for i in range(2*n-2):
        t=1<<i
        if t&k:
            if cj%2:
                ci+=1
            else:
                cj+=1
        else:
            if cj%2:
                cj+=1
            else:
                ci+=1
        res+=[[ci+1, cj+1]]
    for i in res:
        print (*i)
    stdout.flush()