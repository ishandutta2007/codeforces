R=lambda:map(int,raw_input().split())
n,a=input(),R()
x=sorted(a)
y=x[::-1]
for i in xrange(1,n):
    a[i-1],a[i]=a[i],a[i-1]
    if ((a[i]!=a[i-1])and(a!=x)and(a!=y)):
        print i,1+i
        exit()
    a[i-1],a[i]=a[i],a[i-1]
print -1