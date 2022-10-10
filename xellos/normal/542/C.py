N =int(input())
inp =input().split()
F =[0 for i in range(N)]
for i in range(N): F[i] =int(inp[i])-1

ans_small =[0 for i in range(N+1)]
for i in range(N):
	x =i
	y =i
	for j in range(N):
		x =F[x]
		y =F[F[y]]
		if x == y:
			ans_small[j+1] +=1

ans =-1
for i in range(1,N+1):
	if ans == -1:
		if ans_small[i] == N:
			ans =i

#dlhe
pw =[0 for i in range(500)]
for i in range(N):
	vis =[False for j in range(N)]
	vis[i] =True
	x =F[i]
	while vis[x] == False:
		vis[x] =True
		x =F[x]
	vis2 =[False for j in range(N)]
	vis2[x] =True
	x =F[x]
	while vis2[x] == False:
		vis2[x] =True
		x =F[x]
	c =0
	for j in range(N):
		if vis2[j]: c +=1
	j =2
	while j <= c:
		p =0
		while c%j == 0:
			c //=j
			p +=1
		pw[j] =max(pw[j],p)
		j +=1

if ans == -1:
	ans =1
	for i in range(1,500):
		for j in range(pw[i]):
			ans *=i
	ans0 =ans
	while ans <= N:
		ans +=ans0

print(ans)