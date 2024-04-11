input()
a=sorted(map(int,raw_input().split()))
if a[0]:
	a=[-1]
else:
	s=sum(a)
	if s%3:
		for i in a:
			if i%3==s%3:
				a.remove(i)
				break
		else:
			for i in a:
				if i%3:
					a.remove(i)
					break
			for i in a:
				if i%3:
					a.remove(i)
					break
while len(a)>1 and a[-1]==0:
	a.pop()
print ''.join(map(str,a[::-1]))