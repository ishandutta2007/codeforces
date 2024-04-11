import sys
I=lambda:[*map(int,sys.stdin.readline().split())]
prin = sys.stdout.write

t, = I()
for _ in range(t):
	n, = I()
	s1 = input()
	s2 = input()
	o1 = s1.count('1')
	o2 = s2.count('1')
	if o1 != o2 and o1 + o2 != n + 1:
		print(-1)
	else:
		if o1 == o2 and o1 + o2 != n + 1:
			diff = 0
			for i in range(n):
				if s1[i] != s2[i]:
					diff += 1
			print(diff)
		elif o1 + o2 == n + 1 and o1 != o2:
			diff = 0
			for i in range(n):
				if s1[i] == s2[i]:
					diff += 1
			print(diff)
		else:
			diff = 0
			for i in range(n):
				if s1[i] != s2[i]:
					diff += 1
			print(min(diff, n - diff))