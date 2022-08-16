def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
l,r,x,y,k = map_input()
ans = "NO"
for i in range(x,y+1):
    if k*i > r:
        break
    elif k*i < l:
        continue
    ans = "YES"
    break
print(ans)