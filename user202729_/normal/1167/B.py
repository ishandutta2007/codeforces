#!/bin/python
import itertools
import sys
for i in range(1,5):
	print(f'? {i} {i+1}')
sys.stdout.flush()
p=[int(input()) for _ in range(4)]
for a in itertools.permutations([4,8,15,16,23,42]):
	if p==[a[i]*a[i+1] for i in range(4)]:
		print('!',' '.join(map(str,a)))