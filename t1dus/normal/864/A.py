def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
n = int(input())    
a = []
for _ in range(n):
	a.append(int(input()))
b = list(set(a[::]))
if(len(b) == 2 and a.count(a[0]) == n//2):
	print("YES")
	print(b[0],b[1])	
else: print("NO")