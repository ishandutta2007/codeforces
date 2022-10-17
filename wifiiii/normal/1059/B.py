import sys
m,n = [int(i) for i in input().split(' ')]
l = [[] for _ in range(m)]
for i in range(m):
	l[i] = input()
inks = []
for i in range(1, m-1):
	for j in range(1, n-1):
		if l[i-1][j-1] == '#' and l[i][j-1] == '#' and l[i+1][j-1] == '#' and l[i-1][j] == '#' and l[i+1][j] == '#' and l[i-1][j+1] == '#'and l[i][j+1] == '#'and l[i+1][j+1] == '#':
			   inks += [(i-1,j-1),(i,j-1),(i+1,j-1),
					    (i-1,j  )        ,(i+1,j  ),
						(i-1,j+1),(i,j+1),(i+1,j+1),]
for i in range(m):
	for j in range(n):
		if l[i][j] == '#' and not (i,j) in inks:
			print("NO")
			sys.exit()
else:
	print("YES")