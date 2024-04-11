a=set([(i+1)*i/2 for i in range(1,1<<16)])
n=input()
print "YES"if[1 for i in a if n-i in a]else"NO"