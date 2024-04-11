m,n=map(int,raw_input().split())
for i in range(m):
	s=raw_input()
	print "".join("-BW"[((i+j)%2+1)*(s[j]!='-')]for j in range(n))