n=input()
print (n*n+1)/2
for i in range(n):
	print ('C.'*n)[i%2:i%2+n]