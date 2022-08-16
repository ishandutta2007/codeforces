n,x,y = map(int,input().split())
l = 0
r = 0
u = 0
d = 0
for i in range(n):
	a,b = map(int,input().split())
	if a < x:
		l += 1
	if a > x:
		r += 1
	if b < y:
		d += 1
	if b > y:
		u += 1
ans = max([l,r,u,d])
print(ans)
if ans == l:
	print(x-1,y)
elif ans == r:
	print(x+1,y)
elif ans == u:
	print(x,y+1)
else:
	print(x,y-1)