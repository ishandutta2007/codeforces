def kprod(n,k):
    i=2
    kr=[]
    while len(kr)<k-1 and i<=n:
        if n%i==0:
            kr+=[i]
            n/=i
            i=1
        i+=1
    if len(kr)==k-1 and n>1:
        return " ".join([str(i) for i in kr+[n]])
    else:
        return -1
        
n,k=[int(k) for k in raw_input().split(" ")]

print kprod(n,k)