def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()

from collections import Counter
n = int(input())    
a = list_input()
c = Counter(a)
ans = 0
s = set(a)
s1 = []
for i in range(1,n+1):
	if i not in s:
		s1.append(i)		
cur = 0		
left = set([])
for i in range(n):
	if(c[a[i]] > 1):
		if s1[cur] < a[i] or a[i] in left:
			c[a[i]] -= 1
			a[i] = s1[cur]
			cur += 1
			ans += 1
		else: left.add(a[i])
print(ans)			
for i in a: print(i,end=' ')