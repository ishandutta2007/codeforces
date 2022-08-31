for _ in range(int(input())):
	s = input()
	t = input()
	a = [i for i in s]
	a.sort()
	ans = "NO"
	for i in range(len(t)):
		b = []
		for j in range(i,len(t)):
			b.append(t[j])
			b.sort()
			if a == b:
				ans = "YES"
				break
		if(ans == "YES"): break

	print(ans)