import sys

lines = []
for i in range(8):
	lines.append(sys.stdin.readline().strip())

for i in range(8):
	if not (lines[i] == "WBWBWBWB" or lines[i] == "BWBWBWBW"):
		print "NO"
		break
else:
	print "YES"