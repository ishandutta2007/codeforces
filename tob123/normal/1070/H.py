smpl = {}
cntr = {}

def handle(s):
	cur = set()
	for i in range(len(s)):
		for j in range(i + 1, len(s) + 1):
			cur.add(s[i:j])
	# print(cur)
	for c in cur:
		if c not in cntr:
			cntr[c] = 0
		cntr[c] += 1
		smpl[c] = s

n = int(input())
for i in range(n):
	s = input()
	handle(s)
q = int(input())
for i in range(q):
	s = input()
	if s in cntr:
		print(cntr[s], smpl[s])
	else:
		print(0, '-')