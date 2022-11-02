p=int(input())
a=[[i]+[0]*(p-2) for i in range(p)]
for i in range(2,p):
    for j in range(1,p-1):
        a[i][j]=a[i][j-1]*i%p
print sum(a[i].count(1)==1 for i in range(2,p))+(p==2)