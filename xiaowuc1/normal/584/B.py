n = int(raw_input())
a = 1
b = 1
for _ in xrange(n):
	a *= 27
	b *= 7
	a %= 1000000007
	b %= 1000000007
print (a-b+1000000007)%1000000007