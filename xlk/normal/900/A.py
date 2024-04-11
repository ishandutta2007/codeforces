c=[0,0]
for i in range(input()):
	c[int(raw_input().split()[0])<0]+=1
print'yneos'[min(c)>1::2]