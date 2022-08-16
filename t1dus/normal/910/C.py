'''input
3
aa
jj
aa
'''

def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
 
n = int(input())
d = {}
pos = {}
for _ in range(n):
	s = list(input())
	s = s[::-1]
	for i in range(len(s)):
		try:
			d[s[i]] += 10**i
		except:
			d[s[i]] = 10**i
			pos[s[i]] = True
		if i == len(s)-1:
			pos[s[i]] = False	
a = []
b = []
for i in d:
	a.append(d[i])
	if pos[i]:
		b.append(d[i])
if len(b):a.remove(max(b))
a.sort(reverse = True)
# print(a)
ans = 0
for i in range(len(a)):
	ans += (i+1)*a[i]
print(ans)