import sys

s=sys.stdin.readline()
t=sys.stdin.readline()

p=0
for x in t:
	if s[p] == x:
		p = p + 1
print p+1