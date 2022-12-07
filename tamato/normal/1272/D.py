N = int(input())
a = list(map(int, input().split()))

dp_l = [0] * N
dp_r = [0] * N
for i in range(N):
    if a[i] > a[i-1]:
        dp_l[i] = dp_l[i-1] + 1
    else:
        dp_l[i] = 1
dp_r[-1] = 1
for i in range(N-2, -1, -1):
    if a[i] < a[i+1]:
        dp_r[i] = dp_r[i+1] + 1
    else:
        dp_r[i] = 1

if dp_l[-1] == N:
    print(N)
    exit()

ans = max(dp_l[-2], dp_r[1])
for i in range(1, N-1):
    if a[i-1] < a[i+1]:
        ans = max(ans, dp_l[i-1] + dp_r[i+1])
    else:
        ans = max(ans, dp_l[i-1], dp_r[i+1])

print(ans)