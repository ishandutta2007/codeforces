n = input()
z = 0
for i in range(n):
	s, d = map(int, raw_input().split())
	z = max((z + d - s % d) / d * d + s % d, s) 
print z