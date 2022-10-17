T=int(input())
for t in range(T):
	hc,dc=map(int,input().split())
	hm,dm=map(int,input().split())
	k,w,a=map(int,input().split())
	for i in range(k+1):
		if (hm-1)//(dc+i*w)*dm<(hc+(k-i)*a):
			print('YES')
			break
	else:
		print('NO')