'''input
4
6 6 4 4
'''

def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()

ans = 0
d = {}
cnt = 0
n = int(input())
a = list_input()
for i in range(n):
	tot = i 
	cur = cnt
	if a[i] in d:
		tot -= d[a[i]]
		cur -= a[i]*d[a[i]]
	if a[i]-1 in d: 
		tot -= d[a[i]-1]
		cur -= d[a[i]-1]*(a[i]-1)
	if a[i]+1 in d: 
		tot -= d[a[i]+1]
		cur -= d[a[i]+1]*(a[i]+1)
	ans += tot*a[i]-cur;
	cnt += a[i];
	if a[i] not in d: d[a[i]] = 1
	else: d[a[i]] += 1
print(ans)