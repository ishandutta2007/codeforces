n = int(raw_input())

ret = 2*n-1
p = 0
for i in range(n):
	h = int(raw_input())
	ret = ret + abs(h-p)
	p = h
print ret