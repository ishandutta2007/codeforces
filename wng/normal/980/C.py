n,k=[int(k) for k in raw_input().split(" ")]
p=[int(i) for i in raw_input().split(" ")]


assigned=[None]*256
res=[]
for i in p:
    if assigned[i] is None:
        j=i
        while i-j+1<k and j>0 and assigned[j] is None:
            j-=1
        if assigned[j] is not None:
            if i-assigned[j]<k:
                for m in range(j,i+1):
                    assigned[m]=assigned[j]
            else:
                for m in range(j+1,i+1):
                    assigned[m]=j+1
        else:
            for m in range(j,i+1):
                assigned[m]=j
    res+=[str(assigned[i])]

print " ".join(res)