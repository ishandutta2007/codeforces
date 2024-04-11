input()
a=map(int,raw_input().split())
z=min(a)
if a.count(z)>1:
	print 'Still Rozdil'
else:
	print a.index(z)+1