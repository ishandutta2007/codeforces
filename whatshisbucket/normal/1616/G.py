import io,os,sys
read = io.BytesIO(os.read(0, os.fstat(0).st_size))
I = lambda:map(int, read.readline().split())
import time
#I = lambda:map(int, sys.stdin.readline().split())

t, = I()
for _ in range(t):
	n, m = I()
	# if n > 100:
	# 	print(time.time())
	to = [[] for i in range(n)]
	fro = [[] for i in range(n)]
	for i in range(m):
		a, b = I()
		a -= 1
		b -= 1
		to[b].append(a)
		fro[a].append(b)
	# if n > 100:
	# 	print(time.time())
	for i in range(n):
		to[i].sort()
		fro[i].sort()
	# if n > 100:
	# 	print(time.time())
	first = None
	last = None
	for i in range(n - 1):
		if len(fro[i]) == 0 or fro[i][0] != i + 1:
			if first is None:
				first = i
			last = i
	if first is None:
		print(n * (n - 1) // 2)
		continue

	# if n > 100:
	# 	print(time.time())
	y = first
	i = first + 1
	blue = {y}
	red = set()

	ruse = []
	buse = []
	if first == last:
		buse.append(y)

	while i < n - 1:
		#print(i, red, blue)
		i += 1
		if len(to[i]) == 0:
			blue = red = set()
			break
		if to[i][-1] != i - 1:
			newr = set()
			newb = set()
		else:
			newr = red
			newb = blue
		for guy in to[i]:
			if guy < i - 1 and guy in blue:
				newr.add(i - 1)
			if guy < i - 1 and guy in red:
				newb.add(i - 1)
		blue = newb
		red = newr

		if i > last:
			if i - 1 in blue:
				buse.append(i - 1)
			if i - 1 in red:
				ruse.append(i - 1)
	if len(blue) > 0:
		ruse.append(n - 1)
	if len(red) > 0:
		buse.append(n - 1)

	# if n > 100:
	# 	print(time.time())
	# print(i, red, blue)
	# print(ruse, buse)
	i = y
	blue = set()
	red = {y + 1}

	ruse1 = []
	buse1 = []
	ruse1.append(y + 1)
	while i > 0:
		i -= 1
		if len(fro[i]) == 0:
			blue = red = set()
			break
		if fro[i][0] != i + 1:
			newr = set()
			newb = set()
		else:
			newr = red
			newb = blue
		for guy in fro[i]:
			if guy > y + 1:
				break
			if guy > i + 1 and guy in blue:
				newr.add(i + 1)
			if guy > i + 1 and guy in red:
				newb.add(i + 1)
		blue = newb
		red = newr

		if i + 1 in blue:
			buse1.append(i + 1)
		if i + 1 in red:
			ruse1.append(i + 1)
	if len(blue) > 0:
		ruse1.append(0)
	if len(red) > 0:
		buse1.append(0)

	# print(ruse1, buse1)
	# if n > 100:
	# 	print(time.time())
	ruse = set(ruse)
	buse = set(buse)
	ruse1 = set(ruse1)
	buse1 = set(buse1)

	both = ruse & buse
	both1 = ruse1 & buse1
	ruse -= both
	buse -= both
	ruse1 -= both1
	buse1 -= both1
	# print(ruse, buse, both, ruse1, buse1, both1)
	x = len(ruse1) * (len(both) + len(buse)) + len(buse1) * (len(both) + len(ruse)) + len(both1) * (len(both) + len(ruse) + len(buse))
	# print(x)
	if first == last:
		x -= 1
	if y in ruse1 or y in both1:
		x -= 1
	if y + 1 in buse or y + 1 in both:
		x -= 1
	print(x)
	# if n > 100:
	# 	print(time.time())
	# 	exit()