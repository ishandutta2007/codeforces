t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    a.sort()
    out="YES"
    for i in range(n-1):
        if a[i+1]-a[i]>1:
            out="NO"
    print(out)