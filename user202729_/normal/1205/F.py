#!/bin/pypy3
import itertools

def cnt(p):
	cnt_=0
	for l in range(len(p)):
		a=b=p[l]
		#for r in range(l,len(p)):
		for r in range(l+1,len(p)):
			a=min(a,p[r])
			b=max(b,p[r])
			if b-a==r-l:
				cnt_+=1
	return cnt_


def bruteforce(endn):
	for n in range(1,endn):
		ok=[0]*(n*(n+1)//2+1)
		for p in itertools.permutations(range(n)):
			ok[cnt(p)]=1

		print(n," => ",*[i for i,v in enumerate(ok) if v])
		print('   ',
				n+1,
				'...',
				n*(n+1)//2 - 2*n+6,
				n*(n+1)//2 - n+2,
				n*(n+1)//2)

special_cases={
}

def gen0able(n,v):
	if v==n*(n-1)//2:
		return True
	return 0<v<n and v!=n-2

def gen0(n,v):
	if v==n*(n-1)//2:
		return tuple(range(n))

	##assert gen0able(n,v)
	od=lrev(range(0,n,2)) # .., 4, 2, 0
	ev=lrev(range(1,n,2)) # .., 5, 3, 1

	def mv(l,i):
		return lrev(l[len(l)-i:]) + l[:len(l)-i]

	return lrev( mv(ev,v//2) ) + mv(od,(v+1)//2)


def make_special_cases(endn):
	for n in range(1,endn):
		ok=[0]*(n*(n+1)//2+1)
		for p in itertools.permutations(range(n)):
			v=cnt(p)
			if not ok[v]:
				ok[v]=1
				if (n,v) not in special_cases:
					print(f'({n},{v}):{p},')

#make_special_cases(11); raise 1

def lrev(x):
	return tuple(reversed(x))

genable=[[0]*(n*(n-1)//2 + 1) for n in range(101)]

genable[1][0]=1

for n in range(2,len(genable)):
	gn=genable[n]

	for v in range(1,len(gn)):
		if gen0able(n,v): gn[v]=1
		if gn[v]: continue

		if (n,v) in special_cases: gn[v]=1
		if gn[v]: continue

		for r in range(2,n):
			if v== n*(n-1)//2 - (n-r)*(r-1):
				gn[v]=1
				break
		if gn[v]: continue

		for p in range(1,n):
			retpt=p*(p-1)//2+1
			if v-retpt<=0:
				break
			if v-retpt<len(genable[n-p]) and genable[n-p][v-retpt]:
				gn[v]=1
				break

		if gn[v]: continue

		for p in range(1,n):
			retpt=p*(p-1)//2+p
			if v-retpt<=0:
				break
			if v-retpt<len(genable[n-p]) and genable[n-p][v-retpt]:
				gn[v]=1
				break


def gen1r(n,v):
	gn=genable[n]

	if v<0 or v>=len(gn) or not gn[v]: return None
	if gen0able(n,v): return gen0(n,v)

	if (n,v) in special_cases: return special_cases[(n,v)]

	for r in range(2,n):
		if v== n*(n-1)//2 - (n-r)*(r-1):
			ans= tuple(range(n-r)) + lrev(range(n-r,n))
			##assert cnt(ans)==v, (ans,cnt(ans),v, [cnt(l1),retpt])
			return ans

	for p in range(1,n):
		retpt=p*(p-1)//2+1
		if v-retpt<=0:
			break
		if v-retpt<len(genable[n-p]) and genable[n-p][v-retpt]:
			l1=gen1r(n-p,v-retpt)
			##assert cnt(l1) == v-retpt
			if l1.index(n-p-1) > l1.index(0):
				l1=lrev(l1)
			ans= lrev(range(p)) + tuple(x+p for x in l1)
			##assert cnt(ans)==v, (ans,cnt(ans),v, [cnt(l1),retpt])
			return ans

	for p in range(1,n):
		retpt=p*(p-1)//2+p
		if v-retpt<=0:
			break
		if v-retpt<len(genable[n-p]) and genable[n-p][v-retpt]:
			l1=gen1r(n-p,v-retpt)
			##assert cnt(l1) == v-retpt
			if l1.index(n-p-1) > l1.index(0):
				l1=lrev(l1)
			ans= tuple(range(p)) + tuple(x+p for x in l1)
			##assert cnt(ans)==v, (ans,cnt(ans),v, [cnt(l1),retpt])
			return ans

	##assert False


if 0:
	def gen1(n,v):
		for r in range(2,n):
			if v== n*(n-1)//2 - (n-r)*(r-1):
				ans= tuple(range(n-r)) + lrev(range(n-r,n))
				##assert cnt(ans)==v, (ans,cnt(ans),v, [cnt(l1),retpt])
				return ans

		if gen0able(n,v):
			return gen0(n,v)


		for p in range(1,n):
			retpt=p*(p-1)//2+1
			if gen0able(n-p,v-retpt):
				l1=gen0(n-p,v-retpt)
				##assert cnt(l1) == v-retpt
				if l1.index(n-p-1) > l1.index(0):
					l1=lrev(l1)
				ans= lrev(range(p)) + tuple(x+p for x in l1)
				##assert cnt(ans)==v, (ans,cnt(ans),v, [cnt(l1),retpt])
				return ans


def test():
	bruteforceresult={
	1 : '0'.split(),
	2 : '1'.split(),
	3 : '2 3'.split(),
	4 : '1 3 4 6'.split(),
	5 : '1 2 4 5 6 7 10'.split(),
	6 : '1 2 3 4 5 6 7 8 9 11 15'.split(),
	7 : '1 2 3 4 5 6 7 8 9 10 12 13 16 21'.split(),
	8 : '1 2 3 4 5 6 7 8 9 10 11 12 13 14 16 17 18 22 28'.split(),
	9 : '1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 23 24 29 36'.split(),
	10: '1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 24 25 27 30 31 37 45'.split(),
	11: '1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 34 38 39 46 55'.split()
	}

	for n in range(1,12):
		for v in map(int,bruteforceresult[n]):
			l=gen1r(n,v)
			##assert l==None or cnt(l)==v, (n,v, l,cnt(l))
			if l==None:
				print(n,v)

def main():
	for _ in range(int(input())):
		n,k=map(int,input().split())
		k-=n
		l=gen1r(n,k)
		if l==None:
			print('NO')
		else:
			print('YES')
			print(*[x+1 for x in l])

main()