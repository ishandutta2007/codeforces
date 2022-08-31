def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
a = input()
b = input()
c = input()
d = {}
for i in range(26):
    d[a[i]] = b[i]
    d[a[i].upper()] = b[i].upper()
for i in range(10):
    d[str(i)] = str(i)

for i in range(len(c)):
    print(d[c[i]],end='')