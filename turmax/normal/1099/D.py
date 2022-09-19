n=int(input())
parent=list(map(int,input().split()))
s=list(map(int,input().split()))
t=[0 for i in range(n)]
d={i:[] for i in range(n)}
for i in range(n-1):
    x=parent[i]
    d[x-1].append(i+2)
k=[]
for i in range(n):
    if(s[i]==(-1)):
        k.append(i+1)
for y in k:
    z=s[parent[(y-2)]-1]
    b=d[y-1]
    v=1000000000
    for i in b:
        if(s[i-1]<z):
            print(-1)
            exit(0)
        else:
            v=min(v,s[i-1])
    if(v==1000000000):
        s[y-1]=s[parent[y-2]-1]
    else:
        s[y-1]=v
summ=0
for i in range(n-1):
    j=parent[i]
    summ+=(s[i+1]-s[j-1])
print(summ+s[0])