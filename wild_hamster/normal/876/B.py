a=[]
for i in range(100005):
    a.append([])
n,k,m = map(int,input().split())
b = list(map(int,input().split()))
for i in range(n):
    a[b[i]%m].append(b[i])
for i in range(100005):
    if len(a[i]) >= k:
        print("Yes")
        for j in range(k):
            print(a[i][j], end = " ")
        exit(0)
print("No")