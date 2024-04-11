ans = dict()

def go(s):
	if s==0:
		return 0
	if s in ans:
		return ans[s]
	l = len(str(s))
	k = int('1'*l)
	d10 = 10**(l-1)
	cur = 0
	was = s
	while(s >= d10):
		s -= k
		cur += l
	if(s <= 0):
		# print("1", cur, -s, was)
		ans[was] = cur + go(-s)
	else:
		# print("2", cur, s, was)
		best = cur + go(s)
		s -= k
		cur += l
		s = -s
		if s < d10:
			best = min(best, cur + go(s))
		ans[was] = best
	alt = k*10+1-was
	if alt < d10*10:
		ans[was] = min(ans[was], go(k*10+1 - was) + l+1)
	return ans[was]


n = int(input())
print(go(n))