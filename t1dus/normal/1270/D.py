n,k = map(int,input().split())
def inpy(x):
	if x == 0: x = k+1
	print("?",end=" ")
	for i in range(1,k+2):
		if i != x:
			print(i,end=' ')
	print("",flush=True)
	return list(map(int,input().split()))
a = [inpy(i) for i in range(k+1)]
gg = a[0][0]
o = a[0][1]
if a[gg][1] > o: # a[k+1] > a[gg]
	ans = 1
	for i in range(1,k+1):
		if(i == gg): continue
		if(a[i][1] > o): ans += 1
		elif(a[i][1] == o): ans += 0
		else: continue
	print("!",ans)		
else: #a[k+1] < a[gg]
	ans = k
	for i in range(1,k+1):
		# print(i,ans)
		if(i == gg): continue
		if(a[i][1] > o): ans += 0
		elif(a[i][1] == o): ans -= 0
		else: ans -= 1
	print("!",ans)