#[int(k) for k in raw_input().split(" ")]
n,K=[int(k) for k in raw_input().split(" ")]
r=[int(k) for k in raw_input().split(" ")]
menos=[0]*n
for i in range(K):
    a,b=[int(k) for k in raw_input().split(" ")]
    if r[a-1]<r[b-1]:
        a,b=b,a
    if r[b-1]<r[a-1]:
        menos[a-1]+=1
        
sr=sorted(r)
nbbelow={}
for i in range(n):
    if not i or sr[i]!=sr[i-1]:
        nbbelow[sr[i]]=i

for i in range(n):
    print nbbelow[r[i]]-menos[i],
print