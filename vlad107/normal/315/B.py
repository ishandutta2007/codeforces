R=lambda:map(int,raw_input().split())
n,m=R()
a=R()
t=0
for _ in range(m):
    q=R()
    if (q[0]==1):a[q[1]-1]=q[2]-t
    elif (q[0]==2):t+=q[1]
    else:print a[q[1]-1]+t