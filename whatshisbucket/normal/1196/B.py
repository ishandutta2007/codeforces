import sys
input=sys.stdin.readline
q=int(input())
for _ in range(q):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    odds=[]
    for i in range(n):
        if a[i]%2==1:
            odds.append(str(i+1))
    if len(odds)<k or (len(odds)-k)%2==1:
        print("NO")
    else:
        print("YES")
        print(" ".join(odds[:k-1])+" "+str(n))