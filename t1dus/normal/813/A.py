n = int(int(input()))
a = list(map(int,input().split()))
a = sum(a)
m = int(input())
for i in range(m):
    x,y = input().split()
    x,y = int(x),int(y)
    if y >= a:
        print(max(a,x))
        break
else:
    print(-1)