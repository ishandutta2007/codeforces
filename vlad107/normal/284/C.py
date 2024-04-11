n=input()
p,a,s=[0],[0],0
for _ in range(n):
    t=map(int,raw_input().split())
    if (t[0]==1):
        s+=t[1]*t[2]
        a[t[1]-1]+=t[2]
    elif (t[0]==2):
        s+=t[1]
        p+=[t[1]]
        a+=[0]
    else:
        q=len(p)
        a[q-2]+=a[q-1]
        s-=a.pop()+p.pop()
    print (s+.0)/len(p)