import sys
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	b = list(map(int, inpu().split()))
	sml = b[0]
	sml1 = b[1]
	if b[2] == sml + sml1:
		if b[-1] == b[0] + b[1] + b[2]:
			sml2 = b[2]
		else:
			sml2 = b[3]
	else:
		sml2 = b[2]
	print(sml, sml1, sml2)