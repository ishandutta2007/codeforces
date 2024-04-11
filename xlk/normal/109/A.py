n=input()
z=""
while n>0 and n%7:
	n-=4
	z+="4"
if n%7:
	print -1
else:
	print z+n/7*"7"