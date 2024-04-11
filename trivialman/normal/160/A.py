n = int(input())
a = list(map(int, input().split()))
a.sort(reverse=True)
tot = sum(a)
now = 0
for i in range(len(a)):
    now += a[i]
    if(now*2>tot):
        break
print(i+1)