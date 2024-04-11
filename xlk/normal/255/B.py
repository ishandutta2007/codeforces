s=raw_input()
x,y=map(s.count,"xy")
if x>y:
	print "x"*(x-y)
else:
	print "y"*(y-x)