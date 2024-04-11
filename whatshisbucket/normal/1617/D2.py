import sys
inpu=sys.stdin.readline
prin=sys.stdout.write
I=lambda:[*map(int,input().split())]

t = I()[0]
for _ in range(t):
	n = I()[0]
	m = n // 3
	maj = [0] * m
	for i in range(1, n, 3):
		print('?', i, i + 1, i + 2)
		maj[i // 3] = I()[0]
	for i in range(m - 1):
		if maj[i] != maj[i + 1]:
			print('?', 3 * i + 2, 3 * i + 3, 3 * i + 4)
			x = I()[0]
			print('?', 3 * i + 5, 3 * i + 3, 3 * i + 4)
			y = I()[0]
			j = maj[i]
			if x != j:
				imp = 3 * i
				crew = 3 * i + 3
			elif y != j:
				imp = 3 * i + 1
				crew = 3 * i + 4
			else:
				imp = 3 * i + 2
				crew = 3 * i + 5
			if j == 1:
				imp, crew = crew, imp
			bad = i
			break
	vals = [-1] * n
	for i in range(m):
		if i != bad and i != bad + 1:
			if maj[i] == 0:
				print('?', 3 * i + 1, 3 * i + 2, crew + 1)
				x = I()[0]
				if x == 0:
					vals[3 * i] = vals[3 * i + 1] = 0
					print('?', 3 * i + 3, crew + 1, imp + 1)
					vals[3 * i + 2] = I()[0]
				else:
					vals[3 * i + 2] = 0
					print('?', 3 * i + 1, crew + 1, imp + 1)
					vals[3 * i] = I()[0]
					vals[3 * i + 1] = 1 - vals[3 * i]
			else:
				print('?', 3 * i + 1, 3 * i + 2, imp + 1)
				x = I()[0]
				if x == 1:
					vals[3 * i] = vals[3 * i + 1] = 1
					print('?', 3 * i + 3, crew + 1, imp + 1)
					vals[3 * i + 2] = I()[0]
				else:
					vals[3 * i + 2] = 1
					print('?', 3 * i + 1, crew + 1, imp + 1)
					vals[3 * i] = I()[0]
					vals[3 * i + 1] = 1 - vals[3 * i]

	if bad == imp // 3:
		if maj[bad] == 1:
			vals[bad * 3] = vals[bad * 3 + 1] = vals[bad * 3 + 2] = 1
			vals[imp] = 0
		else:
			if imp != bad * 3:
				print('?', bad * 3 + 1, imp + 1, crew + 1)
				vals[bad * 3] = I()[0]
			if imp != bad * 3 + 1:
				print('?', bad * 3 + 2, imp + 1, crew + 1)
				vals[bad * 3 + 1] = I()[0]
			if imp != bad * 3 + 2:
				print('?', bad * 3 + 3, imp + 1, crew + 1)
				vals[bad * 3 + 2] = I()[0]
			vals[imp] = 0
		if maj[bad + 1] == 0:
			vals[bad * 3 + 3] = vals[bad * 3 + 4] = vals[bad * 3 + 5] = 0
			vals[crew] = 1
		else:
			if crew != bad * 3 + 3:
				print('?', bad * 3 + 4, imp + 1, crew + 1)
				vals[bad * 3 + 3] = I()[0]
			if crew != bad * 3 + 4:
				print('?', bad * 3 + 5, imp + 1, crew + 1)
				vals[bad * 3 + 4] = I()[0]
			if crew != bad * 3 + 5:
				print('?', bad * 3 + 6, imp + 1, crew + 1)
				vals[bad * 3 + 5] = I()[0]
			vals[crew] = 1
	else:
		if maj[bad] == 0:
			vals[bad * 3] = vals[bad * 3 + 1] = vals[bad * 3 + 2] = 0
			vals[crew] = 1
		else:
			if crew != bad * 3:
				print('?', bad * 3 + 1, imp + 1, crew + 1)
				vals[bad * 3] = I()[0]
			if crew != bad * 3 + 1:
				print('?', bad * 3 + 2, imp + 1, crew + 1)
				vals[bad * 3 + 1] = I()[0]
			if crew != bad * 3 + 2:
				print('?', bad * 3 + 3, imp + 1, crew + 1)
				vals[bad * 3 + 2] = I()[0]
			vals[crew] = 1
		if maj[bad + 1] == 1:
			vals[bad * 3 + 3] = vals[bad * 3 + 4] = vals[bad * 3 + 5] = 1
			vals[imp] = 0
		else:
			if imp != bad * 3 + 3:
				print('?', bad * 3 + 4, imp + 1, crew + 1)
				vals[bad * 3 + 3] = I()[0]
			if imp != bad * 3 + 4:
				print('?', bad * 3 + 5, imp + 1, crew + 1)
				vals[bad * 3 + 4] = I()[0]
			if imp != bad * 3 + 5:
				print('?', bad * 3 + 6, imp + 1, crew + 1)
				vals[bad * 3 + 5] = I()[0]
			vals[imp] = 0
	print('!', vals.count(0), ' '.join([str(i + 1) for i in range(n) if vals[i] == 0]))