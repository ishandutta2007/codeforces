import sys
z=x=0
for s in sys.stdin:
	if s[0]=='+':
		x+=1
	elif s[0]=='-':
		x-=1
	else:
		z+=(len(s)-s.find(':')-2)*x
print z