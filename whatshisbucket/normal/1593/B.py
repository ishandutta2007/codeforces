t=int(input())
for _ in range(t):
	n=input()
	back = n[::-1]
	if '0' in back:
		z = back.index('0')
		if '0' in back[z+1:]:
			z0 = back[z+1:].index('0')
		else:
			z0 = None
		if '5' in back[z+1:]:
			z5 = back[z+1:].index('5')
		else:
			z5 = None
	else:
		z = None
	if '5' in back:
		f = back.index('5')
		if '2' in back[f+1:]:
			f2 = back[f+1:].index('2')
		else:
			f2 = None
		if '7' in back[f+1:]:
			f7 = back[f+1:].index('7')
		else:
			f7 = None
	else:
		f = None

	sml = len(n)
	if z is not None:
		if z0 is not None:
			sml = min(sml,z0+z)
		if z5 is not None:
			sml = min(sml,z5+z)
	if f is not None:
		if f2 is not None:
			sml = min(sml,f2+f)
		if f7 is not None:
			sml = min(sml, f7+f)
	print(sml)