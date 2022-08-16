n = int(input())
a = []
for i in range(n):
    b = list(map(int,input().split()))
    a.append([b[0],-1])
    a.append([b[1],1])
a.sort()
cur = 0
for i in a:
    cur += i[1]
    if cur <= -3:
        print("NO")
        break
else: print("YES")