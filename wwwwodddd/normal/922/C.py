n, k = map(int, raw_input().split())
k = min(k, 1000)
s = set([])
for i in range(1, k + 1):
	s.add(n % i)
print ['No', 'Yes'][len(s) == k]