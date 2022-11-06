n=int(input())
d={}
for k in range(n):
    nk=input()[0]
    if nk not in d:
        d[nk]=0
    d[nk]+=1

res=0

def pairs(n):
    return n*(n-1)//2

for k in d.values():
    res+=pairs(k//2)+pairs(k-k//2)
    

print(res)