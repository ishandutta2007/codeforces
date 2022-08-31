n = int(input())
a = list(map(int,input().split()))
t = 0
mn = 1000000000
for i in range(1,100):
    cur = 0
    for j in range(n):
        cur += max(0,abs(i-a[j])-1)
    if cur < mn:
        mn = cur
        t = i
print(t,mn)