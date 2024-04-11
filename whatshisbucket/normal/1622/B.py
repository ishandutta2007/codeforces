I=input
for _ in[0]*int(I()):
	n=int(I());p=map(int,I().split());s=I();p=sorted(zip(s,p,range(n)));w=[0]*n
	for i in range(n):w[p[i][2]]=i+1
	print(*w)