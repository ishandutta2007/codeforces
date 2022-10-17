s = input()
n = int(input())
if s == 'ABC' and n < 2000 or s == 'ARC' and n < 2800 or s == 'AGC' and n >= 1200:
	print('YES')
else:
	print('NO')