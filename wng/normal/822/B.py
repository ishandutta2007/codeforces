n,m=[int(k) for k in raw_input().split(" ")]
s=raw_input()
t=raw_input()

res=n
rn=0
ress=" ".join([str(k) for k in range(1,n+1)])

for i in range(m-n+1):
    rr=n
    rs=[]
    for k in range(n):
        if s[k]==t[i+k]:
            rr-=1
    if rr<res:
        res=rr
        rn=i

rss=[]
for k in range(n):
    if s[k]!=t[rn+k]:
        rss+=[k+1]

ress=" ".join([str(k) for k in rss])

print res
print ress