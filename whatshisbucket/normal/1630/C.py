import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

n, = I()
a = I()
sml = [None] * n
big = [None] * n
a = [guy - 1 for guy in a]
for i in range(n):
	if sml[a[i]] is None:
		sml[a[i]] = i
	else:
		big[a[i]] = i

ints = []
for i in range(n):
	if big[i] is not None:
		ints.append((sml[i], big[i]))

if len(ints) == 0:
	print(0)
	exit()
ints.sort()
out = []
ind = 0
big = 0
while ind < len(ints):
	if ints[ind][0] > big:
		big = ints[ind][0]

	farthest = big
	best = None
	while ind < len(ints) and ints[ind][0] <= big:
		if ints[ind][1] > farthest:
			farthest = ints[ind][1]
			best = ints[ind]
		ind += 1
	if best is not None:
		out.append(best)
	big = farthest

tot = n - 1 - len(out)
tot -= out[0][0]
tot -= n - 1 - out[-1][-1]
for i in range(len(out) - 1):
	if out[i][1] < out[i + 1][0]:
		tot -= out[i + 1][0] - out[i][1]

print(tot)