from sys import stdout
from random import randint as ri
n = int(input())
def gcd(x,y):
	#print(x,y)
	if y == 0:
		return x
	return gcd(y,x%y)
l = [n]
def sqrt(x,n):
	for i in range(1,n):
		if i*i%n == x:
			return i
	return -1
for i in range(40):
	cq = ri(1,n-1)
	cq2 = cq*cq%n
	print("sqrt",cq2)
	stdout.flush()
	cans = int(input())
	#cans = sqrt(cq2,n)
	if cans != cq:
		l.append(gcd(abs(cans+cq),n))
		l.append(gcd(abs(cans-cq),n))
l = list(set(l))

nl = []
for i in l:
	for j in l:
		cg = gcd(i,j)
		if cg not in l and cg not in nl:
			nl.append(cg)
p = 0
while p<len(nl):
	for i in l:
		ci = gcd(i,nl[p])
		if ci not in l and ci not in nl:
			nl.append(ci)
	l.append(nl[p])
	p+=1
ans = []
#print(l)
for i in range(len(l)):
	l = sorted(l)
	#print(l)
	ans.append(l[i])
	c = l[i]
	for j in range(len(l)):
		if l[j]%c == 0:
			l[j]//=c
ans = sorted(list(set(ans)))
if ans[0] == 1:
	del ans[0]
print("! "+str(len(ans))+"".join([' '+str(i) for i in ans]))