n = int(raw_input())
ret = -1
l = [int(x) for x in raw_input().split()]
d = 1
add = 0
while l:
	ret += 1
	s = 0 if d > 0 else len(l) - 1
	while s >= 0 and s < len(l):
		if l[s] <= add:
			add += 1
			l.pop(s)
			if d > 0:
				s -= d
		s += d
	d = -d
print ret