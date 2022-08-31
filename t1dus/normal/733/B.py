n = int(input())
a = []
b = []
for _ in range(n):
	x,y = map(int,input().split())
	a.append(x)
	b.append(y)
x = sum(a)
y = sum(b)	
ans = abs(x-y)
ind = 0
for i in range(n):
	z = abs(((x-a[i])+b[i])-((y-b[i])+a[i]))
	if z > ans:
		ans = z
		ind = i+1
print(ind)