import sys
inpu = sys.stdin.readline
prin = sys.stdout.write

x, y = map(int, inpu().split())
if y == x:
	print('YES')
	exit()
x = bin(x)[2:]
y = bin(y)[2:]
ind = 0
for i in range(len(x)):
	if x[i] == '1':
		ind = i
use = x[:ind + 1]
#print(x, y, use)
if use in y:
	ind = y.index(use)
	if '0' not in y[:ind] and '0' not in y[ind + len(use):]:
		print('YES')
		exit()
use = use[::-1]
if use in y:
	ind = y.index(use)
	if '0' not in y[:ind] and '0' not in y[ind + len(use):]:
		print('YES')
		exit()
use = x + '1'
#print(x, y, use)
if use in y:
	ind = y.index(use)
	if '0' not in y[:ind] and '0' not in y[ind + len(use):]:
		print('YES')
		exit()
use = use[::-1]
if use in y:
	ind = y.index(use)
	if '0' not in y[:ind] and '0' not in y[ind + len(use):]:
		print('YES')
		exit()
print('NO')