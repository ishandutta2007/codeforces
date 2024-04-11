n,m=[int(k) for k in raw_input().split(" ")]
diz=[int(k) for k in raw_input().split(" ")]
un=[int(k) for k in raw_input().split(" ")]

both=[k for k in range(1,10) if k in diz and k in un]

if len(both)>0:
    print min(both)
else:
    res1=min(diz)
    res2=min(un)
    rr=min(res1,res2)
    print rr*10+res1+res2-rr