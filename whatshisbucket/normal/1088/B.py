n,k=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
b=[a[0]]
for i in range(n-1):
    if a[i+1]>a[i]:
        b.append(a[i+1]-a[i])
c=len(b)
for i in range(k):
    if i<c:
        print(b[i])
    else:
        print(0)