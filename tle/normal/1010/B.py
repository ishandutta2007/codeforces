import sys
def ask(x):
    print x
    sys.stdout.flush()
    y=int(raw_input())
    if y==0 or y==-2:
        sys.exit(0)
    return y
m,n=map(int,raw_input().split(' '))
t=[0]*n
for i in range(0,n):
    t[i]=ask(1)
p,l,r=-1,1,m
while True:
    mid=(l+r)>>1
    p+=1
    p%=n
    if ask(mid)*t[p]==1:
        l=mid+1
    else:
        r=mid-1