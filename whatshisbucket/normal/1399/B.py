t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    cand=min(a)
    orange=min(b)
    tot=0
    for i in range(n):
        tot+=max(a[i]-cand,b[i]-orange)
    print(tot)