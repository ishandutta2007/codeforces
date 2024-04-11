t = int(input())
for _ in range(t):
	n, m = map(int, input().split())
	s = input()
	currx, curry = 0, 0
	bigx = 0
	smlx = 0
	bigy = 0
	smly = 0
	done = False
	for char in s:
		if char == "U":
			currx -= 1
			if bigx - currx == n:
				done = True
				print(- currx, - smly + 1)
				break
			else:
				smlx = min(smlx, currx)
		elif char == "D":
			currx += 1
			if currx - smlx == n:
				done = True
				print(- smlx + 1, - smly + 1)
				break
			else:
				bigx = max(bigx, currx)
		elif char == "L":
			curry -= 1
			if bigy - curry == m:
				done = True
				print(- smlx + 1, - smly + 1)
				break
			else:
				smly = min(smly, curry)
		elif char == "R":
			curry += 1
			if curry - smly == m:
				done = True
				print(- smlx + 1, - smly + 1)
				break
			else:
				bigy = max(bigy, curry)
	if not done:
		print(- smlx + 1, - smly + 1)