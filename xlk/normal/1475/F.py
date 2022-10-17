Z=input
for _ in range(int(Z())):
	R=range(int(Z()))
	a=[[*map(int,Z())]for i in R]
	Z()
	b=[[*map(int,Z())]for i in R]
	print("YNEOS"[any(a[i][j]^a[0][j]^a[i][0]^a[0][0]^b[i][j]^b[0][j]^b[i][0]^b[0][0]for i in R for j in R)::2])