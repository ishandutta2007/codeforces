n,k=[int(kk) for kk in raw_input().split(" ")]

a=[]
for i in range(4):
    a+=[[int(kk) for kk in raw_input().split(" ")]]
    
spots=a[0]+a[3][::-1]
cars=a[1]+a[2][::-1]
left=k
nbm=0
res=[]
while left>0:
    #print cars
    #print spots
    #print nbm
    vide=None
    for i in range(2*n):
        if cars[i]>0 and cars[i]==spots[i]:
            nbm+=1
            cs=(1,i+1) if i<n else (4,2*n-i)
            res+=["{} {} {}".format(cars[i],cs[0],cs[1])]
            cars[i]=0
            spots[i]=0            
            left-=1
        if not cars[i]:
            vide=i
    if vide is None:
        nbm=-1
        res=[]
        break
    for i in range(vide,vide+2*n):
        i%=2*n
        if cars[i]:
            nbm+=1
            cs=(3,1) if i==0 else ((2,i) if i<=n else (3,2*n-i+1))
            res+=["{} {} {}".format(cars[i],cs[0],cs[1])]
    cars=cars[1:]+cars[:1]
    if nbm>20000: #Mouais j'espere que ca va pas arriver
        nbm=-1
        res=[]
        break

print nbm
print "\n".join(res)