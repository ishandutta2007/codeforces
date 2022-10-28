import sys
I = lambda:[*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, k = I()
	s = input()
	alpha = 'abcdefghijklmnopqrstuvwxyz'
	count = {guy: 0 for guy in alpha}
	for char in s:
		count[char] += 1
	vals = [count[guy] for guy in count]
	pairs = 0
	for guy in vals:
		pairs += guy // 2
	odds = 0
	for guy in vals:
		odds += guy % 2
	sml = pairs // k
	how = k - pairs % k
	if odds + pairs % k >= how:
		print(2 * sml + 1)
	else:
		print(2 * sml)