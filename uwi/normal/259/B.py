import sys

s = []
for x in range(3):
	s.append([int(x) for x in sys.stdin.readline().split(" ")])

x = s[0][1]+s[0][2]
y = s[1][0]+s[1][2]
z = s[2][0]+s[2][1]
k = (x+y+z)/2
s[0][0] = k - x
s[1][1] = k - y
s[2][2] = k - z

for line in s:
	print " ".join([str(x) for x in line])