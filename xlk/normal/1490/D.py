def F(a):
	if not a:return[]
	p=a.index(max(a))
	return [i+1 for i in F(a[:p])]+[0]+[i+1 for i in F(a[p+1:])]
for t in range(int(input())):
	input()
	print(' '.join(map(str,F(list(map(int,input().split()))))))