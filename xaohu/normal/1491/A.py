n, q = [int(i) for i in input().split()]
A = [int(i) for i in input().split()]
ones = 0
for e in A:
	if e == 1:
		ones += 1
for i in range(q):
	t, x = [int(i) for i in input().split()]
	if t == 1:
		x -= 1
		if A[x] == 1:
			ones -= 1
		else:
			ones += 1
		A[x] = 1 - A[x]
	if t == 2:
		if x <= ones:
			print(1)
		else:
			print(0)