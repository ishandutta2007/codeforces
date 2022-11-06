ns=raw_input()
n=int(ns)
l=len(ns)

ok=[]
l9=min(l*9+1,n)
for k in range(n-l9,n+1):
    sd=sum([int(i) for i in str(k)])
    if sd+k==n:
        ok+=[k]

print len(ok)
for k in ok:
    print k