def list_input(): return list(map(int,input().split()))
def map_input(): return map(int,input().split())

n,a,b = map_input()
t = list_input()
ans = c = 0
for i in t:
    if i == 2:
        if b: b -= 1
        else: ans += 2
    else:
        if a: a -= 1
        elif b:
            b -= 1
            c += 1
        elif c: c -= 1
        else: ans += 1
print(ans)