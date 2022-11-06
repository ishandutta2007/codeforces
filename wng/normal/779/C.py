n,k=raw_input().split(" ")
n=int(n)
k=int(k)
a=[int(s) for s in raw_input().split(" ")]
b=[int(s) for s in raw_input().split(" ")]
c=[a[i]-b[i] for i in range(len(a))]
d=sorted(c)
res=sum(b)
for i in range(len(d)):
    if k>0 or d[i]<0:
        res+=d[i]
        k-=1
print res