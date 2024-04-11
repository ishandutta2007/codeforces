n=int(raw_input())


#print n+1
#print "{} 2".format(" ".join([str(k) for k in range(n,0,-1)]))

print n+n/2
a=" ".join([str(k) for k in range(2,n+1,2)])
b=" ".join([str(k) for k in range(1,n+1,2)])
print "{} {} {}".format(a,b,a)