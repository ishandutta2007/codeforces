import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	hc, dc = I()
	hm, dm = I()
	k, w, a = I()
	die = hc // dm
	if hc % dm != 0:
		die += 1
	
	for i in range(k + 1):
		power = dc + w * i
		kill = (hm - 1) // power + 1
		need = (kill - 1) * dm + 1
		if a == 0:
			if need > hc:
				spend = k + 1
			else:
				spend = 0
		else:
			spend = (need - hc - 1) // a + 1
		if spend + i <= k:
			print("YES")
			break
	else:
		print("NO")