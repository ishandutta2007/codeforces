n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
c1 = [0,0,0,0,0,0,0]
c2 = [0,0,0,0,0,0,0]
for i in a:
    c1[i] += 1
for i in b:
    c2[i] += 1
for i in range(6):
    if (c1[i]+c2[i])%2 == 1:
        print(-1)
        break
else:
    ans = 0
    for i in range(6):
        ans += abs(c1[i]-c2[i])
    print(ans//4)