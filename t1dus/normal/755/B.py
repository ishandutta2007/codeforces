n,m = map(int,input().split())
a = set([])
b = set([])
c = set([])
for i in range(n):
	a.add(input())
for i in range(m):
	x = input()
	if x in a:
		c.add(x)
	b.add(x)
a = len(a)
b = len(b)
c = len(c)
if c%2 == 1:
	a += 1
if a > b:
	print("YES")
else:
	print("NO")