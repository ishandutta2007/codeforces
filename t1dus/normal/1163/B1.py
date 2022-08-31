n = int(input())
a = list(map(int,input().split()))
gg = [0]*15
ans = 1
for i in range(n):
	gg[a[i]] += 1
	cnt1 = 0
	s = set([])
	for j in gg:
		if not j: continue
		if j == 1: cnt1 += 1
		else: s.add(j)
	mkc = []
	for j in s: mkc.append(j)	
	# print(s,mkc,cnt1)
	if(len(s) == 0 or i+1 in gg):
		ans = max(ans,i+1)
	if (len(s) == 1 and cnt1 == 1):
		ans = max(ans,i+1)
	if len(s) == 1 and cnt1 == i-1 and mkc[0] == 2:
		ans = max(ans,i+1)
	if len(s) == 2 and cnt1 == 0:
		mkc.sort()
		if mkc[1] == mkc[0]+1:
			bak = 0
			for j in gg:
				if j == mkc[1]: bak += 1
			if bak == 1:
				ans = max(ans,i+1)	 
print(ans)