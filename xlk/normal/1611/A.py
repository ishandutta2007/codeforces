for t in range(int(input())):
	s = input()
	if int(s[-1]) % 2 == 0:
		print(0)
	elif int(s[0]) % 2 == 0:
		print(1)
	else:
		for i in s:
			if int(i) % 2 == 0:
				print(2)
				break
		else:
			print(-1)