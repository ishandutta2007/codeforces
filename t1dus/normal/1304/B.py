n,m = map(int,input().split())
a = [input() for _ in range(n)]
gg1 = 0
gg2 = 0
x1 = ""
x2 = ""
x3 = ""
for i in range(n):
	if(a[i] == a[i][::-1]) and gg1 == 0: 
		gg1 = 1
		x2 += a[i]
	else:
		for j in range(i+1,n):
			if(a[i] == a[j][::-1]):
				gg2 += 1
				x1 += a[i]
				x3 += a[j][::-1]		
				break
x3 = x3[::-1]				
if(0):
	print(2*m*gg2)
	print(x1+x3)	
else:	
	print((2*gg2+gg1)*m)		
	print(x1+x2+x3)	
# ababwxyzijjizyxwbaba
# ababwxyzijjibabazyxw