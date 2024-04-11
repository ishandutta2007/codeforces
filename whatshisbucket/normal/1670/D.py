import io,os
read = io.BytesIO(os.read(0, os.fstat(0).st_size))
I = lambda: [*map(int, read.readline().split())]

# import sys
# I=lambda:[*map(int,sys.stdin.readline().split())]

created = [0]
for i in range(1, 50000):
	a, b, c = i // 3, i // 3, i // 3
	if i % 3 > 0:
		a += 1
	if i % 3 > 1:
		b += 1
	created.append(2 * (a * b + b * c + a * c))

t, = I()
for _ in range(t):
	n, = I()
	approx = int((n * 1.5) ** 0.5)
	if created[approx - 1] >= n:
		print(approx - 1)
	elif created[approx] >= n:
		print(approx)
	else:
		print(approx + 1)