s=raw_input()
x,z=0,0
for i in s:
	if i=='(':
		x+=1
	elif x>0:
		x-=1
		z+=2
print z