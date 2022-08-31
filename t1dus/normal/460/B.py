a,b,c = map(int,input().split())
ans = []
for s in range(1,100001):
	x = b*(s**a)+c
	gg = 0
	if x <= 0: continue
	for i in str(x):
		gg += int(i)
	# print(x,gg)
	if gg == s and x <= 10**9:
		ans.append(x)
print(len(ans))	
for i in ans: print(i,end=' ')