n, m = map(int, raw_input().split())
a = [ map(int, raw_input().split()) for i in range(n)]
b = [ map(int, raw_input().split()) for i in range(n)]
 
ok = True
for i in range(n):
	for j in range(m):
		if a[i][j] > b[i][j]:
			a[i][j], b[i][j] = b[i][j], a[i][j]
		if i > 0:
			ok &= a[i][j] > a[i-1][j] and b[i][j] > b[i-1][j]
		if j > 0:
			ok &= a[i][j] > a[i][j-1] and b[i][j] > b[i][j-1]
 
print("Possible" if ok else "Impossible")