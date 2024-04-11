a,b,p,x=[int(k) for k in raw_input().split(" ")]


res=0
mp=range(p)
ma=[0 for k in range(p-1)]
ppm1=p*(p-1)
for i in range(0,p-1):
    ma[i]=(ma[i-1]*a)%p if i else 1
##Oooh, si n%p=ma[p-1-n%p-1] c bon!
    #Candidat
    mp=(ma[i]*b)%p
    mpm1=(-i)%(p-1)
    mppm1=((mpm1-mp)*(p-1)+mpm1)%ppm1
    #print mp,mpm1,mppm1
    if mppm1<=x:
        res+=(x-mppm1)/ppm1 +1
print res