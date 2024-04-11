n=int(input(""))
l = str(input(""))
L=[0]*10
for i in l:
	if(i=='L'):
		for j in range(0,10):
			if(L[j]==0):
				L[j]=1
				break
	elif(i=='R'):
		for j in range(9,-1,-1):
			if(L[j]==0):
				L[j]=1
				break
	else:
		L[int(i)]=0	
print(*L,sep="")