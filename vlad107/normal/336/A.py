x,y=map(int,raw_input().split())
if (x>0):
	print 0,(abs(x)+abs(y))*[-1,1][y>0],(abs(x)+abs(y))*[-1,1][x>0],0
else:print (abs(x)+abs(y))*[-1,1][x>0],0,0,(abs(x)+abs(y))*[-1,1][y>0]