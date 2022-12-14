import sys
import math
a,b,c=map(int,sys.stdin.readline().split())
d,e,f=map(int,sys.stdin.readline().split())
ds=math.sqrt((a-d)**2+(b-e)**2)
if ds>=c+f:
	print((ds-c-f)/2)
elif ds<=abs(c-f):
	print((abs(c-f)-ds)/2)
else:
	print(0)