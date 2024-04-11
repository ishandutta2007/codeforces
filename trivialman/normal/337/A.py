n, m = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
minx = 99999999
for i in range(m-n+1):
    minx = min(minx, a[i+n-1]-a[i])
print(minx)