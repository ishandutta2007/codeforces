import sys
inpu=sys.stdin.readline
prin=sys.stdout.write
I=lambda:[*map(int,inpu().split())]

q, = I()
queries = []
for i in range(q):
	queries.append(I())

final = {}
rev = []
for i in range(q - 1, -1, -1):
	query = queries[i]
	if query[0] == 1:
		if query[1] in final:
			rev.append(final[query[1]])
		else:
			rev.append(query[1])
	else:
		x, y = query[1], query[2]
		if y in final:
			final[x] = final[y]
		else:
			final[x] = y

print(' '.join(str(guy) for guy in rev[::-1]))