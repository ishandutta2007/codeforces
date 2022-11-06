
k=int(input())

i=1
n=10
while i**n<k:
    i+=1

t= [i]*n

def prod(t):
    res=1
    for i in t:
        res*=i
    return res

kk=0
while True:
    tt=[t[_] if _!=kk else t[_]-1 for _ in range(n)]
    kk+=1
    if prod(tt)<k:
        break
    t=tt

w="codeforces"

print("".join([w[i]*t[i] for i in range(n)]))