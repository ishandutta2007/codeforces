t = int(input())
m = 10**9 + 7
for i in range(t):
	n, k=map(int,input().split())
	b = bin(k)[2:]
	add = 1
	tot = 0
	for i in range(len(b)):
		if b[-i-1] == '1':
			tot += add
			tot %= m
		add *= n
		add %= m
	print(tot)