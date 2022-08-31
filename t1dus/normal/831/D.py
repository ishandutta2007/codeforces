def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
n,k,p = map_input()
a = list_input()
b = list_input()
a.sort()
b.sort()
ans = 1000000000000000000
for i in range(k-n+1):
    cur = 0
    c1 = 0
    c2 = i
    while c1 < n:
        cur = max(abs(a[c1]-b[c2])+abs(b[c2]-p),cur)
        c1 += 1
        c2 += 1
    ans = min(ans,cur)
print(ans)