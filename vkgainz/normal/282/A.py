n = int(input())

ans = 0
for i in range(n):
	s = str(input())
	if s[1]=='+':
		ans = ans+1
	else:
		ans = ans-1
print(ans)