n = input()
c = [-9] + [0] * n
p, q = 0, 0
for i in map(int, raw_input().split()):
	if p < i:
		q = p
		p = i
		c[p] -= 1
	elif q < i:
		q = i
		c[p] += 1
print c.index(max(c))