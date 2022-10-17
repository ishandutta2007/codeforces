for i in range(input()):
	a,b,k=map(float,raw_input().split())
	print "%.9f"%(1/(1/(a-b)+k*k*(a-b)/a/b))