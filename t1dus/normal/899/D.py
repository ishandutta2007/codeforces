'''input
3
'''

def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
n = int(input())    
mx = len(str(n+n))-1
ad = 10**mx
cur = ad-1
ans = 0

for i in range(10):
	# print(cur," --")
	lol = n+n-1
	if lol < cur: break
	# n+x = cur, x = cur-n
	x = cur-n
	if x >= 1: ans += (n-x+1)//2
	else: 
		# 1+x = cur,x = cur-1
		x = cur-1
		ans += x//2

	cur += ad
if n >= 5:
	print(ans)
else:
	print((n*(n-1))//2)