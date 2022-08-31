def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
n = int(input())    
a = list_input()
a1 = []
for i in range(1,n):
    if a[i-1] < a[i]:
        a1.append(1)
    elif a[i-1] > a[i]:
        a1.append(3)
    else:
        a1.append(2)

if sorted(a1) == a1:
    print("YES")
else:
    print("NO")