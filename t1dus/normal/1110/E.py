n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
x = []
y = []
for i in range(n-1):
    x.append(a[i+1]-a[i])
for i in range(n-1):
    y.append(b[i+1]-b[i])
x.sort()
y.sort()
# print(x,y)
if x == y and a[0] == b[0] and a[n-1] == b[n-1]:
    print("Yes")
else:
    print("No")