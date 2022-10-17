n = input()
a = set(map(int, raw_input().split()))
s = []
p = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67]
for i in a:
	b = 0
	for j in p:
		while i % j == 0:
			i /= j
			b ^= 1 << j
	for j in s:
		b = min(b, b ^ j)
	if b > 0:
		s.append(b)
print pow(2, n - len(s), 10 ** 9 + 7) - 1