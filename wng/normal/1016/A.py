n,m=[int(k) for k in raw_input().split(" ")]
a=[int(k) for k in raw_input().split(" ")]


sa=[0]
res=[]
for i in range(n):
    sa+=[sa[-1]+a[i]]

    res+=[str(sa[-1]/m-sa[-2]/m)]

print " ".join(res)