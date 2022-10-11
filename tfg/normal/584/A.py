(n, t) = raw_input().split()
if t == '10' and n == '1':
	print('-1')
else:
	ans = 1
	for i in range(1, int(n)):
		ans = ans * 10
	if ans % int(t) != 0:
		ans = ans + int(t) - (ans % int(t))
	print(ans)