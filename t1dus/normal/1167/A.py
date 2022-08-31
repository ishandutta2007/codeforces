for _ in range(int(input())):
	n = int(input())
	s = input()
	for i in range(len(s)-10):
		if(s[i] == '8'):
			print("YES")
			break
	else:
		print("NO")