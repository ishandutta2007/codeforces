t = int(input())
for tt in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	for i in range(n):
		s, t = input().split()
		a[i] = (a[i] + t.count('D') - t.count('U')) % 10
	print(*a)