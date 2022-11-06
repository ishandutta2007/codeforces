n,m=[int(k) for k in raw_input().split(" ")]
a=[int(k) for k in raw_input().split(" ")]

b=[0]*101

for k in a:
    b[k]+=1

res=0
nbk=(max(b)-1)/m+1
for k in range(101):
    if b[k]:
        res+=max(0,nbk*m-b[k])
        #print k,b[k],nbk

print res