x,y,a,b=map(int,raw_input().split())
t=[[i,j] for i in xrange(a,x+1) for j in xrange(b,min(y+1,i))]
print len(t)
print "\n".join(map(lambda x:" ".join(map(str,x)),t))