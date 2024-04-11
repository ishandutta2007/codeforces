t=int(input())
for _ in range(t):
	n,k = map(int,input().split())
	coords = list(map(int,input().split()))
	coords.sort(reverse=True)
	total = n-1
	i = 0
	while i<k and total >= n-coords[i]:
		total -= (n-coords[i])
		i += 1
	print(i)