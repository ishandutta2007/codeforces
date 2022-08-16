for _ in range(int(input())):
	s = input()
	cnt = s.count('0')
	for i in s:
		if i == '1': break
		cnt -= 1
	for i in range(len(s)-1,-1,-1):
		if s[i] == '1': break
		cnt -= 1
	print(max(cnt,0))