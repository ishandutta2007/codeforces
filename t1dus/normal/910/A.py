'''input
4 2
1001
'''

def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
n,d = map_input()
s = input()
cur = 0
cnt = 0
while cur < n-1:
	j = -1
	for i in range(cur+1,min(cur+d+1,n)):
		if s[i] == '1': j = i
	if j == -1:
		print(-1)
		break
	cur = j
	cnt += 1
else: print(cnt)