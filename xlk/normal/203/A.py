x,t,a,b,da,db=map(int,raw_input().split())
A=[0]+[a-i*da for i in range(t)]
B=[0]+[b-i*db for i in range(t)]
for i in A:
	if x-i in B:
		print "YES"
		quit()
print "NO"