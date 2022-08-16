def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
n = int(input())    
a = list_input()
b = sorted(a)
cnt = 0
pos = 0
pos2 = 0
for i in range(n):
    if b[i] != a[i]:
        cnt += 1
        if cnt == 1:
            pos = i
        elif cnt == 2:    
            pos2 = i
if cnt > 2:
    print("NO")
    exit()
a[pos],a[pos2] = a[pos2],a[pos]
if a == b:
    print("YES")
else:
    print("NO")