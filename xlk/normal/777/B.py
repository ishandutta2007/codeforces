n = input()
a = raw_input()
b = raw_input()
c = [list(a).count(str(i)) for i in range(10)]
d = [list(b).count(str(i)) for i in range(10)]

t = 0
for j in range(10):
	t += c[j]
	t -= d[j]
	if t < 0:
		t = 0

print t

s = t = 0
for j in range(9):
	t += c[j]
	s += min(t, d[j + 1])
	t -= min(t, d[j + 1])

print s