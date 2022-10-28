def merge(a,b):
    inda=0
    indb=0
    lena=len(a)
    lenb=len(b)
    d=[a[-1]+b[-1]+1000]
    a+=d
    b+=d
    c=[]
    inversions=0
    for i in range(lena+lenb):
        if a[inda]<b[indb]:
            c.append(a[inda])
            inda+=1
        else:
            c.append(b[indb])
            indb+=1
            inversions+=lena-inda
    return((c,inversions))
def mergesort(a):
    if len(a)<=1:
        return((a,0))
    split=len(a)//2
    b=a[:split]
    c=a[split:]
    d=mergesort(b)
    e=mergesort(c)
    f=merge(d[0],e[0])
    return((f[0],f[1]+d[1]+e[1]))
n=int(input())
a=list(map(int,input().split()))
b=[]
for guy in a:
    if guy!=-1:
        b.append(guy)
invs=mergesort(b)[1]
negs=len(a)-len(b)
pairs=(negs*(negs-1))//2
used=[0]*n
for guy in a:
    if guy!=-1:
        used[guy-1]+=1
unused=[0]
for i in range(n-1):
    unused.append(unused[-1]+1-used[i])
negsseen=0
mix=0
for i in range(n):
    if a[i]==-1:
        negsseen+=1
    else:
        mix+=unused[a[i]-1]*(negs-negsseen)+negsseen*(negs-unused[a[i]-1])
num=invs*2*negs+pairs*negs+mix*2
denom=2*negs
if negs==0:
    print(invs%998244353)
else:
    for i in range(denom):
        if (998244353*i+1)%denom==0:
            inv=(998244353*i+1)//denom
            break
    print((num*inv)%998244353)