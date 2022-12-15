n = int(input())
ans = 0
for i in range(n):
	a,b,c = map(int,input().split())
	chk = 0
	chk = a+b+c
	if(chk >= 2):
		ans += 1

print(ans)