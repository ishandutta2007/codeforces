s=raw_input()
z=0
while len(s)>1:
	s=str(sum(map(int,s)))
	z+=1
print z