import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

M = 10 ** 9 + 7
facs = [1]
ifacs = [1]
for i in range(1, 5000):
	facs.append(facs[-1] * i % M)
	ifacs.append(ifacs[-1] * pow(i, M - 2, M) % M)

def binom(n, m):
	if m < 0 or m > n:
		return 0
	return facs[n] * ifacs[m] * ifacs[n - m] % M

t, = I()
for _ in range(t):
	n, = I()
	s = [*input()]
	t = [*input()]
	for i in range(n):
		if i % 2 == 0:
			if s[i] == '1':
				s[i] = '0'
			elif s[i] == '0':
				s[i] = '1'
			if t[i] == '1':
				t[i] = '0'
			elif t[i] == '0':
				t[i] = '1'
	s1 = s.count('1')
	sq = s.count('?')
	t1 = t.count('1')
	tq = t.count('?')

	qs = [0]
	qt = [0]
	os = [0]
	ot = [0]
	qs1 = []
	qt1 = []
	os1 = []
	ot1 = []
	for i in range(n - 1):
		if s[i] == '?':
			qs1.append(sq - qs[-1] - 1)
			qs.append(qs[-1] + 1)
		else:
			qs1.append(sq - qs[-1])
			qs.append(qs[-1])
		if s[i] == '1':
			os1.append(s1 - os[-1] - 1)
			os.append(os[-1] + 1)
		else:
			os1.append(s1 - os[-1])
			os.append(os[-1])
		if t[i] == '?':
			qt1.append(tq - qt[-1] - 1)
			qt.append(qt[-1] + 1)
		else:
			qt1.append(tq - qt[-1])
			qt.append(qt[-1])
		if t[i] == '1':
			ot1.append(t1 - ot[-1] - 1)
			ot.append(ot[-1] + 1)
		else:
			ot1.append(t1 - ot[-1])
			ot.append(ot[-1])
	qs1.append(0)
	qt1.append(0)
	os1.append(0)
	ot1.append(0)

	tot = 0
	for i in range(n):
		for j in range(n):
			if s[i] != '0' and t[j] != '0':
				tot += abs(i - j) * binom(qs[i] + qt[j], qt[j] + ot[j] - os[i]) * binom(qs1[i] + qt1[j], qt1[j] + ot1[j] - os1[i])
				tot %= M
	print(tot)