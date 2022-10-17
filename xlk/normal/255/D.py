n,x,y,c=map(int,raw_input().split())
def C(t):
	return t*t+(t+1)*(t+1)-sum(map(lambda x:max(x,0)**2,[t-x+1,t-y+1,x+t-n,y+t-n]))+sum(map(lambda x:max(x,0)*(max(x,0)+1)/2,[t-x-y+1,t-n+x-y,t-n+y-x,t-2*n+x+y-1]))
l,r=-1,2*n
while l<r-1:
	m=l+r>>1
	if C(m)<c:
		l=m
	else:
		r=m
print r