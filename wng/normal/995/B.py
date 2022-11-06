n=[int(k) for k in raw_input().split(" ")][0]
a=[int(k) for k in raw_input().split(" ")]

ts=[0]*(n)


for i in range(2*n):
    ts[a[i]-1]+=i

cs=sorted(range(n),key=lambda x:ts[x])
aa=a[:]
res=0
for i in cs:
    js=[j for j in range(len(a)) if a[j]==i+1]
    #print i,a,js
    res+=sum(js)-1
    a=[k for k in a if k!=i+1]

print res