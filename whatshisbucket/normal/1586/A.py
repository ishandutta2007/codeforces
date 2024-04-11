def isprime(n):
	if n in {2,3,5,7,11}:
		return True
	for i in range(2,int(n**0.5)+2):
		if n%i == 0:
			return False
	return True
t=int(input())
for _ in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	s = sum(a)
	if not isprime(s):
		print(n)
		print(" ".join([str(i+1) for i in range(n)]))
		continue
	sml = max(a)+1
	ind = -1
	for i in range(n):
		if a[i] < sml and not isprime(s-a[i]):
			ind = i
			sml = a[i]

	print(n-1)
	out = ""
	for i in range(n):
		if i != ind:
			out += str(i+1)+" "
	print(out[:-1])