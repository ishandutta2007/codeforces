def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
a,b,f,k = map_input()
tot = a*k
s = 2*a-f
cur = 0
cnt = b
go = 0
ans = 0
while cur < tot:
	go = 1-go
	if(go == 1):
		if cnt < s and cnt < tot-cur:
			if(cnt < f):
				print(-1)
				break
			cnt = b
			ans += 1
			cnt -= (a-f)
		else: cnt -= a	
	else:
		if cnt < a+f and cnt < tot-cur:
			if(cnt < a-f):
				print(-1)
				break
			cnt = b
			ans += 1
			cnt -= (f)
		else:cnt -= a	
	cur += a
	# print(cur,cnt,ans)	
	if(cnt < 0):
		print(-1)
		break
else:
	print(ans)