def s(i):
	return sum(map(int,str(i)))
n=input()
for i in range(max(1,int(n**.5)-999),int(n**.5)+999):
	if i*(i+s(i))==n:
		print i
		exit()
print -1