t = int(input())
def factors(n):
	out = []
	for i in range(1,int(n**0.5)+1):
		if n%i == 0:
			out.append(i)
			out.append(n//i)
	if out[-1] == out[-2]:
		out.pop(-1)
	return out
for _ in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	a.sort()
	counts = {}
	for guy in a:
		if guy in counts:
			counts[guy]+=1
		else:
			counts[guy] = 1
	done = False
	for guy in counts:
		if counts[guy] >= n//2:
			print(-1)
			done=True
	if done:
		continue
	diffs = []
	for i in range(n):
		for j in range(i+1,n):
			diffs.append(a[j]-a[i])
	allfactors = []
	memo = {}
	zs = 0
	for guy in diffs:
		if guy == 0:
			zs += 1
		else:
			if guy in memo:
				allfactors.append(memo[guy])
			else:
				f = factors(guy)
				memo[guy] = f
				allfactors.append(f)
	times = {}
	for fs in allfactors:
		for f in fs:
			if f in times:
				times[f] += 1
			else:
				times[f] = 1
	for guy in times:
		times[guy] += zs
	complete = []
	for guy in times:
		if times[guy] >= (n//2)*(n//2-1)//2:
			complete.append(guy)
	complete.sort(reverse = True)
	done = False
	for guy in complete:
		if done:
			break
		mods = {}
		for boi in a:
			m = boi%guy
			if m in mods:
				mods[m] += 1
			else:
				mods[m] = 1
		for i in mods:
			if mods[i] >= n//2:
				done=True
				print(guy)
				break