_,b = map(int,input().split())
one = 0
for i in [int(x) for x in input().split()]:
	one = one*b+i
_,b = map(int,input().split())
two = 0
for i in [int(x) for x in input().split()]:
	two = two*b+i
if one<two:
	print('<')
if one>two:
	print('>')
if one==two:
	print('=')