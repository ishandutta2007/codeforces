n = int(input())
a = []
for i in range(n):
    a.append(list(map(int,input().split())))
m = int(input())
b = []
for i in range(m):
    b.append(list(map(int,input().split())))    
a.sort()
b1 = b[::]
b.sort()
b1.sort(key = lambda x: x[1])
ans = 0
for i in a:
    ans = max(ans,b[-1][0]-i[1])
    ans = max(ans,i[0]-b1[0][1])
print(ans)