def dvoich(n):
    v=[]
    import math
    while True:
        x=2**(math.trunc(math.log(n,2)))
        v.append(x)
        n-=x 
        if(n==0):
            return(v)
n,k=map(int,input().split())
d=sorted(dvoich(n),reverse=True)
f=len(d)
g=0
m=[]
if(f>k):
    print("NO")
elif(n<k):
    print("NO")
elif(f==k):
    print("YES")
    for t in d:
        print(int(t),end=" ")
else:
    print("YES")
    while True:
        try:
            x=d[-1]
        except:
            for t in d:
                    print(int(t),end=" ")
            for t in m:
                    print(int(t),end=" ")
            exit(0)
        if(x==1):
            d.pop()
            m.append(x)
        else:
            if(f<k):
                d.pop()
                d.append(x/2)
                d.append(x/2)
                f+=1
            elif(f==k):
                for t in d:
                    print(int(t),end=" ")
                for t in m:
                    print(int(t),end=" ")
                break