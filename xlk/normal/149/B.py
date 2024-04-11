def conv(n,b):
	if not n:
		return 0
	if int(n[-1],36)>=b:
		return 100
	return int(n[-1],36)+conv(n[:-1],b)*b
h,m=raw_input().split(":")
z=filter(lambda x:conv(h,x)<24 and conv(m,x)<60,range(1,100))
if z==[]:
	print 0
elif z[-1]==99:
	print -1
else:
	print ' '.join(map(str,z))