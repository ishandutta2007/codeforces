n=int(input())
a=list(map(int,input().split()))
a.sort()
p1=0
p2=n//2
b=[]
for i in range(n):
    if (i%2==0):
        b.append(a[p2])
        p2=p2+1
    else:
        b.append(a[p1])
        p1=p1+1
ans=0
for i in range(1,n-1):
    if (b[i]<b[i-1]) and (b[i]<b[i+1]):
        ans=ans+1
print(ans)
for i in range(n):
    if (i==n-1):
        print(b[i])
    else:
        print(b[i],end=' ')