n = input()
a = raw_input().split()
d = {}
for i in range(n):
	d[a[i]] = i
print min(d, key=d.get)