import sys

def r():
    return list(map(int, input().split()))

n, k = map(int, input().split())
a = r()

cnt4 = n
cnt2 = 2*n
cnt1 = 0
for i in range(k):
    x = min((a[i]+1)//4, cnt4)
    cnt4 -= x
    a[i] = max(0, a[i]-4*x)

cnt2 += cnt4
cnt1 += cnt4
for i in range(k):
    x = min(a[i]//2, cnt2)
    cnt2 -= x
    a[i] = max(0, a[i]-2*x)

cnt1 += cnt2
for i in range(k):
    cnt1 -= a[i]

if (cnt1 < 0):
    print('NO')
else:
    print('YES')