n,k=map(int,input().split())
a=list(map(int,input().split()))
for i in range(n):
    a[i]=(a[i],i)
a=[x for x in reversed(sorted(a))]
b=[]
s=0
for i in range(k):
    b+=[a[i][1]]
    s+=a[i][0]
print(s)
b=sorted(b)
b[k-1]=n-1
p=-1
for x in b:
    print(x-p,end=' ')
    p=x