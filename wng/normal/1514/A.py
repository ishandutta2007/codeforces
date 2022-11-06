#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
t=int(input())
for nbt in range(t):
    n=[int(i) for i in input().split()][0]
    a=[int(i) for i in input().split()]
    isok=False
    for i in a:
        if int((i+.5)**0.5)**2!=i:
            isok=True
            break
    if isok:
        print("YES")
    else:
        print("NO")