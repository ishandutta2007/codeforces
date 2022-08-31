z,b,c = map(int,input().split())
m = int(input())
a = []
for _ in range(m):
    x,y = input().split()
    if y == 'USB':
        a.append([int(x),1])
    else:
        a.append([int(x),2])
cost = ans = 0        
a.sort()
for i in a:
    if i[1] == 1:
        if z:
            z -= 1
            ans += 1
            cost += i[0]
        elif c:
            c -= 1
            ans += 1
            cost += i[0]
    else:
        if b:
            b -= 1
            ans += 1
            cost += i[0]
        elif c:
            c -= 1
            ans += 1
            cost += i[0]
print(ans,cost)