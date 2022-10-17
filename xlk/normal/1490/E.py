for t in range(int(input())):
	input()
	s=0
	z=[]
	for x,i in sorted((x,i+1)for i,x in enumerate(map(int,input().split()))):
		if s<x:
			z=[]
		s+=x
		z.append(i)
	print(len(z))
	print(' '.join(map(str,sorted(z))))