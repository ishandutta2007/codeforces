#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
t=int(input())

a=[[0 for j in range(101)] for i in range(101)]

for i in range(1,101):
    a[i][0]=i
    a[0][i]=i
    for j in range(1,101):
        a[i][j]=a[i][j-1]+(i+1)

for nbt in range(t):
    n,m,k=[int(i) for i in input().split()]
    if a[n-1][m-1]==k:
        print("YES")
    else:
        print("NO")