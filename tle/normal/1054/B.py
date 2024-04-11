n=int(raw_input())
mx=-1
aa=-1
a=map(int,raw_input().split(' '))
for t in xrange(0,len(a)):
    x=a[t]
    if x>mx+1:
        aa=t+1
        break
    mx=max(mx,x)
print aa