s=raw_input()

n=len(s)

nbr=(n-1)/20+1

nbc=n/nbr
while nbc*nbr<n:
    nbc+=1

a=[nbc]*nbr
nb=nbc*nbr-n

for i in range(nb):
    a[i]-=1

print nbr,nbc
start=0
for k in range(nbr):
    print s[start:start+a[k]]+"*"*(nbc-a[k])
    start+=a[k]