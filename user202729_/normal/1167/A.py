#!/bin/python
n=int(input())
for _ in range(n):
	input()
	s=input()
	try:
		ans=len(s)-s.index('8')>=11
	except ValueError:
		ans=False
	print('YES' if ans else 'NO')