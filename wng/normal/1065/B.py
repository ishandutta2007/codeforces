n,m=[int(k) for k in raw_input().split(" ")]

mmin=max(0,n-2*m)
mmax=0
smmax=0

while mmax<n and smmax<m:
    smmax+=mmax
    mmax+=1

print mmin,n-mmax