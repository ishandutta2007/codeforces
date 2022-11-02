n,m=map(int,raw_input().split())
a=[[0]*(n+3) for i in xrange(n+3)]
for i in xrange(1,m+1):
    x,y=map(int,raw_input().split())
    for r,c in [[x+u,y+v] for u in xrange(3) for v in xrange(3)]:
        a[r][c]+=1
        if (a[r][c]==9):
            print i
            exit(0)
print -1