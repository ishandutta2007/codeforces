import sys
n = input()

print (n*n+1)/2
for i in xrange(n):
	for j in xrange(n):
		if (i+j)%2 == 0:
			sys.stdout.write('C')
		else:
			sys.stdout.write('.')
	print