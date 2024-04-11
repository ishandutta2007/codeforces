n,p=[int(k) for k in raw_input().split(" ")]
a=[0]*n
b=[0]*n

for i in range(n):
    a[i],b[i]=[int(k) for k in raw_input().split(" ")]

c=[float(b[i])/a[i] for i in range(n)]

ds=sorted(range(n),key=lambda xx:c[xx])

x=c[ds[0]]
spent=0
spending=0
i=0
currint=0
eps=10**(-5)

while spent<=p*x and i<n:
  #  print i,x,ds[i],spent,spending,wt,a[ds[i]],b[ds[i]],c[ds[i]]
    spending+=a[ds[i]]
    wt=c[ds[i+1]]-c[ds[i]]  if i<n-1 else "inf"
    if wt=="inf":
        if spending>p:
            x+=float(x*p-spent)/(spending-p)
    else:
        if (spending-p)*wt<=(x*p-spent):
            spent+=spending*wt
            x+=wt
        else:
            x+=(x*p-spent)/float(spending-p)
            spent+=spending*((x*p-spent)/float(spending-p))+eps
 #   print i,x,ds[i],spent,spending,wt,a[ds[i]],b[ds[i]],c[ds[i]]
    i+=1

if spending>p:
    print x
else:
    print -1