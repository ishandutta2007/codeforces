n = int(input())
a = list(map(int,input().split()))
ans = 0
b = [0,0,0,0,0]
for i in a:
    b[i] += 1
ans += b[4]
b[1] = max(0,b[1]-b[3])
ans += b[3]
ans += b[2]//2
b[2] %= 2
b[1] += 2*b[2]
ans += (b[1]+3)//4
print(ans)