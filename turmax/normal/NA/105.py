def rasl_d(a):
    r=2
    x=[]
    while(r*r<=a):
           if(a%r==0): 
                   x.append(r)
                   s=r
                   r=2
                   a/=s
           else:
               r+=1
    if(r*r>a):
        x.append(a)
    return x 
def delnumber(n):
    if(n==1):
        return(1)
    b=1
    x=rasl_d(n)
    u=x[0:len(x):1]
    for i in set(x):
        a=u.count(i)
        b*=(a+1)
    return(b)
print(delnumber(int(input())))