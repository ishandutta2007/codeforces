def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()

def dist(a,b,k):
    a = max(a,k)
    a *= 2
    cnt = 0
    while a < b:
        a *= 2
        cnt += 1
    return cnt    
    
n,k = map_input()
a = list_input()
a.sort()
ans = dist(k,a[0],k)
for i in range(1,n):
    ans += dist(a[i-1],a[i],k)
    
print(ans)