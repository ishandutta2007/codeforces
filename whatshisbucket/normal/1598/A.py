t=int(input())
for _ in range(t):
	n=int(input())
	a=input()
	b=input()
	done=False
	for i in range(n):
		if a[i]=="1" and b[i]=="1":
			done=True
			print("NO")
			break
	if not done:
		print("YES")