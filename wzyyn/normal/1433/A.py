a=[]
v=[]
for i in range(1,10):
    x=0
    for j in range(4):
        x=x*10+i
        a.append(x)
        v.append(j+1)
T=int(input())
for i in range(T):
    x=int(input())
    ans=0
    for j in range(len(a)):
        ans=ans+v[j]
        if a[j]==x:
            print(ans)