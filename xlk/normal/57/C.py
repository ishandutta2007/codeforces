p=1000000007
def C(n,m):
	return reduce(lambda x,y:x*(n-y)*pow(y+1,p-2,p)%p,[1]+range(m))
n=input()
print C(2*n,n)-n