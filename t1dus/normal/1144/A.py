for i in range(int(input())):
	s = list(input())
	s.sort()
	ans = "Yes"
	for i in range(1,len(s)):
		if(ord(s[i]) != ord(s[i-1])+1):
			ans = "No"
			break
	print(ans)