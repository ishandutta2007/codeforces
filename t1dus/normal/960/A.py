'''input
aabc
'''

def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
s = input()
a = s.count('a')
b = s.count('b')
c = s.count('c')
ans = "YES"
if(a == 0 or b == 0): ans = "NO"
if(c != a and c != b): ans = "NO"
for i in range(len(s)-1):
	if(s[i] > s[i+1]): ans = "NO"
print(ans)