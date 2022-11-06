
n=int(raw_input())
a=[int(k) for k in raw_input().split(" ")]
b=[int(k) for k in raw_input().split(" ")]

m1=0
m2=0
for k in range(n):
    if b[k]>m1:
        m2=m1
        m1=b[k]
    elif b[k]>m2:
        m2=b[k]
        
if sum(a)<=m1+m2:
    print "YES"
else:
    print "NO"