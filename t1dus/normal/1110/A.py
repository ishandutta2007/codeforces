b,k = map(int,input().split())
a = list(map(int,input().split()))
ans = 0
for i in range(k-1):
    ans += (b%2)*(a[i]%2)
ans += a[k-1]
if ans%2 == 0:
    print("even")
else:
    print("odd")