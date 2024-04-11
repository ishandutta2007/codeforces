n = input()
s, z, a = 0, 0, 1
for i in sorted(map(float, raw_input().split()))[::-1]:
	z = z * (1 - i) + a * i
	a *= 1 - i
	s = max(s, z)
print s