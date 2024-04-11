def pp(c):
	i=ord(c)
	s="+"*i+"."+"-"*i
	print s

ans=str(eval(raw_input()))
for c in ans:
	pp(c)