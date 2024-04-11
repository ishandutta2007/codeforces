t=int(input(""))
for i in range(t):
	n=int(input(""))
	X= list(map(int, input("").split())) 
	L=[]
	T=[]
	count=0
	for j in X:
		if(j%3==0):
			count+=1
		else:
			T.append(j)
	L=list(map(lambda x:x%3,T))
	a,b=0,0
	for j in L:
		if(j==1):
			a+=1
		if(j==2):
			b+=1
	if(a>=b):
		count=count+b+int((a-b)/3)
	else:
		count=count+a+int((b-a)/3)
	print(count)