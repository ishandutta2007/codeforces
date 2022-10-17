t=int(input())
for _ in range(t):
    n=int(input())
    s=set()
    arr=list(map(int,input().split()))
    for i in range(0,n):
        s.add((arr[i]+i)%n)
    if len(s)==n:
        print("YES")
    else:
        print("NO")