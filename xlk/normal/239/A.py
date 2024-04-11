y,k,n=map(int,raw_input().split())
a=range(y/k*k+k-y,n-y+1,k)
if a==[]:
	print -1
print ' '.join(map(str,a))