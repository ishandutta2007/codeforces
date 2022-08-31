n = int(input())
a = []
for i in range(n):
    a.append(int(input()))
for i in range(1<<n):
    lol = 0
    for j in range(n):
        if((1<<j)&i):
            lol += a[j]
        else:
            lol -= a[j]
    if (lol%360) == 0:
        print("YES")
        break
else:
    print("NO")