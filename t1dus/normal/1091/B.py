n = int(input())
a = []
b = []
for i in range(n):
    a.append(list(map(int,input().split())))
for i in range(n):
    b.append(list(map(int,input().split())))
a.sort(reverse=True)
b.sort()
print(b[0][0]+a[0][0],b[0][1]+a[0][1])