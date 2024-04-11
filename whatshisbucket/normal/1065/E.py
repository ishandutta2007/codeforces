n,m,a=map(int,input().split())
b=list(map(int,input().split()))
for i in range(m):
    if i==0:
        diffs=[b[0]]
    else:
        diffs.append(b[i]-b[i-1])
powers=[a%998244353]
for i in range(30):
    powers.append(powers[-1]**2%998244353)
def power(x,y,binpowers):
    prod=1
    bits=bin(y)[2:]
    bits=bits[::-1]
    for i in range(len(bits)):
        if bits[i]=="1":
            prod*=binpowers[i]
            prod%=998244353
    return prod
maxi=b[-1]
prod1=power(a,n-2*maxi,powers)
for guy in diffs:
    newprod=power(a,guy,powers)
    newprod=(newprod*(newprod+1))//2
    newprod%=998244353
    prod1*=newprod
    prod1%=998244353
print(prod1)