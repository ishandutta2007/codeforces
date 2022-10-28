import sys
inpu = sys.stdin.readline
prin = sys.stdout.write
n,m = map(int,inpu().split())
strs = []
for i in range(n):
	strs.append(inpu())
bycol = [0]*m
for i in range(1,n):
	for j in range(1,m):
		if strs[i-1][j] == 'X' and strs[i][j-1] == 'X':
			bycol[j] += 1
sums = [bycol[0]]
for i in range(1,m):
	sums.append(sums[-1]+bycol[i])
q = int(inpu())
for i in range(q):
	a,b = map(int,inpu().split())
	if a == m:
		prin("YES\n")
	else:
		if sums[b-1] - sums[a-1] == 0:
			prin("YES\n")
		else:
			prin("NO\n")