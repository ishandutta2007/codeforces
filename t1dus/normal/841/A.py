def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
n,k = map_input()
s = input()
ans = 0
for i in s:
    ans = max(ans,s.count(i))
if ans <= k:
    print("YES")
else:
    print("NO")