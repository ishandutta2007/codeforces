def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
n = int(input())    
a = list(input())
ans = 0
for i in range(n):
	for j in range(i,n):
		b = a[i:j+1]
		for k in b:
			if k.lower() != k:
				break
		else:
			b = set(b)
			ans = max(ans,len(b))
print(ans)