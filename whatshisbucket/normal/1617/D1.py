import sys
inpu=sys.stdin.readline
prin=sys.stdout.write
I=lambda:[*map(int,input().split())]

t = I()[0]
for _ in range(t):
	n = I()[0]
	vals = [0] * n
	for i in range(n - 2):
		print('?', i + 1, i + 2, i + 3)
		vals[i] = I()[0]
	print('?', n - 1, n, 1)
	vals[-2] = I()[0]
	print('?', n, 1, 2)
	vals[-1] = I()[0]
	for i in range(n - 1):
		if vals[i] != vals[i + 1]:
			one = i
			two = (i + 3) % n
			break
	correct = [0] * n
	correct[one] = -1
	correct[two] = -1
	for i in range(n):
		if i != one and i != two:
			print('?', i + 1, one + 1, two + 1)
			correct[i] = I()[0]
	safe = correct.index(1)
	imp = correct.index(0)
	print('?', safe + 1, imp + 1, one + 1)
	correct[one] = I()[0]
	print('?', safe + 1, imp + 1, two + 1)
	correct[two] = I()[0]
	print('!', correct.count(0), ' '.join([str(i + 1) for i in range(n) if correct[i] == 0]))