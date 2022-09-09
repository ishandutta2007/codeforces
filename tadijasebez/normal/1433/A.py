t = int(input())
for tc in range(t):
	n = input()
	ans = (int(n[0]) - 1) * 10 + len(n) * (len(n)+1) // 2
	print(ans)