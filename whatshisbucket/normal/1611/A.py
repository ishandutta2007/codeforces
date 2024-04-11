t = int(input())
for _ in range(t):
	s = input()
	if s[-1] in {'2', '4', '6', '8'}:
		print(0)
	elif '2' not in s and '4' not in s and '6' not in s and '8' not in s:
		print(-1)
	elif s[0] in {'2', '4', '6', '8'}:
		print(1)
	else:
		print(2)