t = int(input())
for _ in range(t):
	n = int(input())
	rows = [0]*n
	cols = [0]*n
	counts = {}
	for i in range(n):
		a,b = map(int,input().split())
		rows[a-1]+=1
		cols[b-1]+=1
		if (a-1,b-1) in counts:
			counts[(a-1,b-1)] += 1
		else:
			counts[(a-1,b-1)] = 1
	total = (n*(n-1)*(n-2))//6
	for guy in counts:
		x,y = guy
		a = counts[guy]
		total -= (a*(a-1)*(a-2))//6
		total -= (a*(a-1)*(n-a))//2
		total -= a*(rows[x]-a)*(cols[y]-a)
	print(total)