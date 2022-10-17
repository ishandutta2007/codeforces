import itertools
a = map(int, raw_input().split())
for i in itertools.combinations(a, 3):
	if sum(i) * 2 == sum(a):
		print 'YES'
		exit()
print 'NO'