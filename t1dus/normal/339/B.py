n,m = map(int,input().split())
a = list(map(int,input().split()))
if m == 1:
    print(a[0]-1)
else:
    ans = 0
    for i in range(1,m-1):
        if a[i] < a[i-1]:
            ans += n
    ans += a[-1]-1
    if a[-1] < a[-2]:
        ans += n
    print(ans)