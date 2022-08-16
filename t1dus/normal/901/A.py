h = int(input())
a = list(map(int,input().split()))
f = False
for i in range(h):
	if a[i] > 1 and a[i+1] > 1:
		f = True
if(not f):
	print("perfect")
else:
	cur = 0
	cur2 = 0
	x = []
	y = []
	bruh = False
	for i in range(h+1):
		if i and a[i] > 1 and a[i-1] > 1 and bruh == False:
			x.append(cur2)
			for j in range(a[i]-1): x.append(cur)
			bruh = True
		else:
			for j in range(a[i]): x.append(cur)
		for j in range(a[i]): y.append(cur)	
		cur = len(x)
		cur2 = len(x)-1				
		# print(i,x,y)
	print("ambiguous")	
	for i in x:	
		print(i,end=' ')
	print("")
	for i in y:	
		print(i,end=' ')