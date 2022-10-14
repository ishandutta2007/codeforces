import math

def ni():
    return int(input())
def vals():
    return list(map(int, input().split()))
def nextLine():
    return input()

n, k= vals()
a = vals()

cnt = [0 for i in range(k)]

for i in range(n):
    cnt[i % k] += a[i]

choice = -1
mx = int(1e18)
for i in range(k):
    if cnt[i] < mx:
        choice = i + 1
        mx = cnt[i]
print(choice)