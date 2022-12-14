#!/bin/python3
from itertools import*

moves =[(x*mx,y*my) for mx,my,(x,y) in product( (-1,1),(-1,1), ( (1,2),(2,1) ) )]

def ac(l,x):
	if l==0: return 0
	return l[x] if 0<=x<len(l) else 0

def work():
	x=1
	while x:
		x=0
		for r in range(len(a)):
			for c in range(len(a[0])):
				if not a[r][c] and sum(ac(ac(a,r+dr),c+dc) for dr,dc in moves)>=4:
					a[r][c]=1
					x=1

for n in [int(input())]:
	#print(' ===== n=',n)
	cand=set()

	#for x in (0,1):
	#	for y in range(-1000,1000):
	#		if y%3!=0: cand.add((x,y))
	#
	#for y in [0]:
	#	for x in range(-1000,1000):
	#		cand.add((x,y))

	for i in range(1000):
		for x,y in ( (0,i),(i,0),(i,1),(-i,0),(-i,1),(0,-i) ):
			if x==0 or x%3!=1:
				if n==len(cand): break
				cand.add((x,y))

	assert len(cand)==n

	#NN=25
	#a=[[0]*(NN*2) for x in range(NN*2)]
	#for x,y in sorted(cand,key=lambda a:abs(a[0])+abs(a[1]))[:n]:
	#	a[x+NN][y+NN]=1

	#for r in a: print(''.join('-#'[x] for x in r))
	#print('===')
	#nn=sum(sum(r) for r in a)
	#print(nn)

	#work()

	#for r in a: print(''.join('-#'[x] for x in r))
	#print('===')

	#have=sum(sum(r) for r in a)
	#print(have)
	#need=nn**2//10
	#print('need',need)

	#assert have>=need, n

	for x,y in cand: print(x,y)