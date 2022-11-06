n=int(raw_input())
a=[int(k) for k in raw_input().split(" ")]

a=sorted(a)
b=range(1,n+1,2)
c=range(2,n+1,2)

res=1000000
for t in (b,c):
    mys=sum([abs(t[i]-a[i]) for i in range(n/2)])
   # print mys
    res=min(res,mys)

print res