t = int(input())
for _ in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	s = input()
	red = []
	blue = []
	for i in range(n):
		if s[i] == "B":
			blue.append(a[i])
		else:
			red.append(a[i])
	blue.sort()
	red.sort(reverse = True)
	good = True
	for i in range(len(blue)):
		if blue[i] < i + 1:
			good = False
	for i in range(len(red)):
		if red[i] > n - i:
			good = False
	if good:
		print("YES")
	else:
		print("NO")