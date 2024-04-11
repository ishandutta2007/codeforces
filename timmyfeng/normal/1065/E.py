M=(119<<23)+1
n,m,a =[int(x)for x in raw_input().split()]
b=[0]+[int(x)for x in raw_input().split()]
r=pow(a,n-2*b[-1],M)
for i in xrange(1,m+1):
    d=b[i]-b[i-1]
    r=r*((pow(a,2*d,M)+pow(a,d,M))%M*((M + 1)/2)%M)%M
print r