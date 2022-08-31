def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
n = int(input())    
a = list_input()
k = sum(a)
cur = 0
s = set([0])
pref = [0]
for i in a:
    pref.append(pref[-1]+i)
    s.add(pref[-1])
for i in range(n):
    s.remove(pref[i])
    if (k/2 + a[i]) in s:
        print("YES")
        break
else:
    a.reverse()
    cur = 0
    s = set([0])
    pref = [0]
    for i in a:
        pref.append(pref[-1]+i)
        s.add(pref[-1])
    for i in range(n):
        s.remove(pref[i])
        if (k/2 + a[i]) in s:
            print("YES")
            break
    else:
        print("NO")