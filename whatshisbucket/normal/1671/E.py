# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

n, = I()
x = 2 ** n - 1
s = input()
smls = [None] * x
for i in range(x // 2, x):
	smls[i] = s[i]
diff = 0
for j in range(x // 2 - 1, -1, -1):
	a = smls[2 * j + 2]
	b = smls[2 * j + 1]
	if a != b:
		diff += 1
	if a < b:
		smls[j] = s[j] + a + b
	else:
		smls[j] = s[j] + b + a
print(pow(2, diff, 998244353))