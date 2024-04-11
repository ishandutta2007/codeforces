n=int(input())
a=[list(map(int, input().split())) for i in range(n)]
chosen=set()
p=[0]*n
for i in range(1, n+1):
    b=-1
    for j in range(n):
        if not j in chosen and all(a[j][k]<=i for k in range(n)) and all(a[k][j]<=i for k in range(n)):
            b=j
    p[b]=i
    chosen.add(b)
print(*p)