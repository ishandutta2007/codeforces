n=int(raw_input())
L=[int(k) for k in raw_input().split(" ")]

d=0
res=0
for k in L[::-1]:
    if d<=0:
        res+=1
    d=max(d-1,k)
    
print res