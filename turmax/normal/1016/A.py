m,n=map(int,input().split())
a=[int(i) for i in input().split()]
z=0
for k in range(m):
    u=a[k]+z 
    print((u)//n,end=" ")
    z=(u%n)