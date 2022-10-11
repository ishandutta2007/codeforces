def valid(n):
	i = 2
	while i * i <= n:
		if n % (i*i) == 0:
			return False
		i += 1
	return True

n = int(raw_input())

ret = 1

i = 1
while i*i <= n:
	if n%i == 0:
		if valid(i):
			ret = max(ret, i)
		if valid(n/i):
			ret = max(ret, n/i)
	i += 1
print ret