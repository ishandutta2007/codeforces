n = int(input())
s = input()

cs = sum([int(i) for i in s])
if cs*2 == n:
	print(2)
	print(s[:-1],s[-1])
else:
	print(1)
	print(s)