'''input
3
3 1 2
'''

def check(a):
	for i in range(len(a)-1):
		if(abs(a[i]-a[i+1]) >= 2): return False
	return True

n = int(input())
a = list(map(int,input().split()))
ans = "YES"
while(a):
	if(not check(a)):
		ans = "NO"
		break
	ind = 0
	mx = a[0]
	for i in range(1,n):
		if(a[i] > mx):
			mx = a[i]
			ind = i
	n -= 1
	del(a[ind])
print(ans)