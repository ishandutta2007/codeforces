def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
n = int(input())
n *= 2    
a = list_input()
a.sort()
ans = 10000000000000
for i in range(n):
	for j in range(i+1,n):
		b = []
		for k in range(n):
			if k != i and k != j:
				b.append(a[k])
		cur = 0
		for k in range(0,n-2,2):
			cur += b[k+1]-b[k]
		# print(i,j,b,cur)	
		ans = min(ans,cur)
print(ans)