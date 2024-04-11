h=set([x*(x+1)/2 for x in xrange(1,int(5e4))])
n=input()
print "YES"if ([n-i in h for i in h].count(1)>0)else"NO"