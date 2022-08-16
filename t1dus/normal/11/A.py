n,d = map(int,input().split())
a = list(map(int,input().split()))

cnt = 0

for i in range(1,n):
    if a[i] <= a[i-1]:
        x = a[i-1]-a[i]
        x -= x%d
        x += d
        cnt += x//d
        a[i] += x
print(cnt)