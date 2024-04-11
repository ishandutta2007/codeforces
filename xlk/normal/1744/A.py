t = int(input())
for tt in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	s = input()
	z = 'YES'
	for i in range(n):
		for j in range(n):
			if a[i] == a[j] and s[i] != s[j]:
				z = 'NO'
	print(z)