n=[int(k) for k in raw_input().split(" ")][0]

d={}

for k in ["A","B","C","AB","AC","BC","ABC"]:
    d[k]=10**10

for i in range(n):
    a,b=raw_input().split(" ")
    a=int(a)
    b="".join(sorted(b))
    for k in d:
        if k in b:
            d[k]=min(d[k],a)


res=d["A"]+d["B"]+d["C"]
res=min(res,d["ABC"])
res=min(res,d["A"]+d["BC"])
res=min(res,d["B"]+d["AC"])
res=min(res,d["C"]+d["AB"])


if res>1000000:
    print -1
else:
    print res