a = []
a.append(list(input().split()))
n = int(input())
for _ in range(n):
    a.append(list(input().split()))
x,y = a[0]
print(x,y)
for i in range(1,n+1):
    if a[i][0] == x:
        x = a[i][1]
    else:
        y = a[i][1]
    print(x,y)