#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
t=int(input())
for nbt in range(t):
    n,k,w=[int(i) for i in input().split()]
    if n*(w+1)>=k and n<=k*(w+1):
        print("YES")
    else:
        print("NO")