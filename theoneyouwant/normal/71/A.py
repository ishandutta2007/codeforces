n = int(input())

for i in range(n):
	s = input()
	l = len(s)
	if(l > 10):
		print(s[0],l-2,s[-1], sep = '')
	else:
		print(s)