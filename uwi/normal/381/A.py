n = input()
a = map(int, raw_input().split())

score = [0]*2
for i in xrange(n):
	if a[0] > a[-1]:
		score[i%2] += a.pop(0)
	else:
		score[i%2] += a.pop(-1)
print score[0], score[1]