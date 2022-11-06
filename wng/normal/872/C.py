
def f(p):
    if p<13:
        if p in [1,2,3,5,7,11]:
            return -1
        if p in [9]:
            return 1
        if p in [4,6,8,10,12]:
            return p/4
    else:
        res=0
        if p%2==1:
            p-=9
            res+=1
        return res+ p/4
        


n=int(raw_input())
r=[0]*n
for i in range(n):
    r[i]=int(raw_input())
    print f(r[i])