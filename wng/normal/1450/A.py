#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
t=int(input())
for nbt in range(t):
    n=[int(i) for i in input().split()]
    s=input()
    print("".join(sorted(s)))