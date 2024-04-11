#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
mod=10**9+7

t=int(input())
for nbt in range(t):
    n,k=[int(i) for i in input().split()]
    print(pow(n,k,mod))