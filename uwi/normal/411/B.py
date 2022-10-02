n,m,k=map(int,raw_input().split())
sc = []
for i in xrange(n):
	lsc = map(int,raw_input().split())
	sc.append(lsc)

tdead = [0]*n
locking = [0]*(k+1)
for t in xrange(m):
	for i in xrange(n):
		if tdead[i] == 0:
			locking[sc[i][t]] += 1
	for i in xrange(n):
		if tdead[i] == 0:
			if sc[i][t] > 0 and locking[sc[i][t]] >= 2:
				tdead[i] = t + 1
			else:
				locking[sc[i][t]] -= 1
for _ in tdead:
	print _