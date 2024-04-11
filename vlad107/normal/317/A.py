x,y,m=map(long,raw_input().split())
if (x>=m)|(y>=m):
    print 0
elif (x<=0)&(y<=0):
    print -1
else:
    if (x<y):x,y=y,x
    t=0
    while (x<m):
        u=max(1,(x-y)/x-1)
        x,y,t=y+u*x,x,t+u
        if (x<y):x,y=y,x
    print t