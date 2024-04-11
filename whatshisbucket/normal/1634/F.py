# import sys
# I = lambda: [*map(int, sys.stdin.readline().split())]

import io,os
read = io.BytesIO(os.read(0, os.fstat(0).st_size))
I = lambda: read.readline().split()

n, q, M = map(int, I())
F = [1, 1]
period = None
for i in range(n - 1):
	F.append((F[-1] + F[-2]) % M)

A = [*map(int, I())]
B = [*map(int, I())]
d = [(A[i] - B[i]) % M for i in range(n)]

fd = [d[0]]
if n > 1:
	fd.append((d[1] - d[0]) % M)
for i in range(2, n):
	fd.append((d[i] - d[i - 1] - d[i - 2]) % M)

s = sum(fd)
out = []

for i in range(q):
	ss, l, r = I()
	if ss.decode('utf-8') == 'A':
		mul = 1
	else:
		mul = -1
	l = int(l) - 1
	r = int(r)
	s -= fd[l]
	fd[l] = (fd[l] + mul) % M
	s += fd[l]
	if r + 1 < n:
		s -= fd[r + 1]
		fd[r + 1] = (fd[r + 1] - mul * F[r - l - 1]) % M
		s += fd[r + 1]
	if r < n:
		s -= fd[r]
		fd[r] = (fd[r] - mul * F[r - l]) % M
		s += fd[r]
	if s == 0:
		out.append('YES')
	else:
		out.append('NO')

print('\n'.join(out))