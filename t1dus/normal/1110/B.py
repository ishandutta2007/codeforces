n,m,k = map(int,input().split())
a = list(map(int,input().split()))
a.sort()
ans = a[n-1]-a[0]+1
k -= 1
b = []
for i in range(n-1):
    b.append(a[i+1]-a[i]-1)
b.sort(reverse = True)
ind = 0
k = min(k,len(b))
while k:
    ans -= b[ind]
    k -= 1
    ind += 1
print(ans)