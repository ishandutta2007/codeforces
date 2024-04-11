n=input()
a=[-1,-1,-1,210]
if n<4:
	print a[n]
else:
	print '1'+'0'*(n-4)+"%03d"%(210-pow(10,n-1,210))