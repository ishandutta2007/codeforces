def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
n,k = map_input()
a = list_input()
b = list_input()
pos = set()
pref = []
cur = 0
for i in a:
    cur += i
    pref.append(cur)
for j in pref:
    pos.add(b[0]-j)
ans = 0
for i in pos:
    s = set(b)
    for j in pref:
        s.discard(i+j)
    if len(s) == 0:
        ans += 1
print(ans)