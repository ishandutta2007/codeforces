t=int(input())
for _ in range(t):
	n=int(input())
	M=set()
	T=set()
	W=set()
	R=set()
	F=set()
	guys = [M,T,W,R,F]
	for i in range(n):
		a = list(map(int, input().split()))
		for j in range(5):
			if a[j]==1:
				guys[j].add(i)
	done = False
	for i in range(5):
		for j in range(i+1,5):
			if not done:
				if len(guys[i]) >= n//2 and len(guys[j]) >= n//2 and len(guys[i]|guys[j])==n:
					done=True
					print("YES")
	if not done:
		print("NO")