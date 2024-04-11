import sys
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	n = int(inpu())
	bigrams = inpu().split()
	done = False
	for i in range(n - 3):
		if bigrams[i][1] != bigrams[i + 1][0]:
			done = True
			bigrams.insert(i + 1, bigrams[i][1] + bigrams[i + 1][0])
			break
	if not done:
		bigrams.append(bigrams[-1][1] + 'a')
	for i in range(n - 2):
		bigrams[i] = bigrams[i][0]
	print(''.join(bigrams))