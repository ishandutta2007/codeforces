for _ in range(int(input())):
	s = input()
	a = []
	for i in s: a.append(i)
	a.append(1)
	a.append(1)
	a.append(1)
	n = len(s)
	if(n <= 2):
		print(0)
		print("")
		continue
	ans = []
	for i in range(0,n-2):
		if [a[i],a[i+1],a[i+2]] == ["o","n","e"]:
			ans.append(i+2)
			a[i+1] = 1
		elif [a[i],a[i+1],a[i+2]] == ["t","w","o"]:
			if(a[i+3] == "n" and a[i+4] == "e"):
				ans.append(i+3)
				a[i+2] = 1
			else:
				ans.append(i+2)
				a[i+1] = 1	

	print(len(ans))
	for i in ans:
		print(i,end=' ')	
	print()