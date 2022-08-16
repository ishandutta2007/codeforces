def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
n = int(input())    
s = input().split()
ans = 0
for i in s:
    cur = 0
    for j in i:
        if j.upper() == j:
            cur += 1
    ans = max(ans,cur)        
print(ans)