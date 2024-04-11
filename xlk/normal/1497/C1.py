for s in[*open(0)][1:]:
	n=int(s.split()[0])
	print(*[[n>>1,n>>2,n>>2],[n-1>>1,n-1>>1,n&-n]][n&3>0])