n = input()
a = map(int, raw_input().split())
d = 0
for i in a[::-1]:
	d = abs(d - i)
print (sum(a) - d) / 2, (sum(a) + d) / 2