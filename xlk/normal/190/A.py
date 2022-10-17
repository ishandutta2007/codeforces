n,m=map(int,raw_input().split())
if not n and m:
	print "Impossible"
else:
	print max(n,m),n+m-(m!=0)