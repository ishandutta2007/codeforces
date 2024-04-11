s = input()
n = len(s)

ans = -1

def f(x):
	if x[0] == '0' and len(x) > 1:
		return -1000000000000000000000000000000000000000000000000
	ret = int(x)
	if ret > 1000000:
		return -1000000000000000000000000000000000000000000000000
	return ret

for i in range(1, n):
	for j in range(i + 1, n):
		ans = max(ans, f(s[0:i]) + f(s[i:j]) + f(s[j:]))

print(ans)