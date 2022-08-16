x0,y0,ax,ay,bx,by = map(int,input().split())
xs,ys,t = map(int,input().split())
dn = [[x0,y0]]
while dn[-1][0] <= 1e20 and dn[-1][1] <= 1e20:
	dn.append([dn[-1][0]*ax+bx,dn[-1][1]*ay+by])
for i in range(len(dn)):
	dn[i][0] -= xs
	dn[i][1] -= ys
ans = 0
for i in range(len(dn)):
	for j in range(len(dn)):
		gg = abs(dn[i][0])+abs(dn[i][1])+abs(dn[j][0]-dn[i][0])+abs(dn[j][1]-dn[i][1])
		if gg <= t:
			ans = max(ans,abs(j-i)+1)
print(ans)