n=input()
a=map(int,raw_input().split())
r=0
for i in xrange(n):
    s=0
    for j in xrange(i,n):
        s^=a[j]
        r=max(r,s)
print r