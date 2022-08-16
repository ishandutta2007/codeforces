for _ in range(int(input())):
	a = input()
	b = input()
	c = input()
	f = 1
	for i in range(len(c)):
		if a[i] != c[i] and b[i] != c[i]: f = 0
	if(f): print("YES")
	else: print("NO")