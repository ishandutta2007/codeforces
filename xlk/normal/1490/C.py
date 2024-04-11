for t in range(int(input())):
	n=int(input())
	i=1
	while i**3<n:
		j=int((n-i**3)**(1/3)+0.5)
		if i**3+j**3==n:
			print('YES')
			break
		i+=1
	else:
		print('NO')