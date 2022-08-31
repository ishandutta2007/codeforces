def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
n,m = map_input()
cnt = 0
upp = n+1
low = -1
left = -1
right = m+1
for i in range(n):
    a = list(input())
    cnt += a.count('B')
    for j in range(m):
        if a[j] == 'B':
            upp = min(upp,i)
            low = max(low,i)
            left = max(left,j)
            right = min(right,j)
x = abs(upp-low)+1 
y = abs(right-left)+1
s = max(x,y)
# print(upp,low,left,right)
if cnt == 0:
    print(1)
elif s > n or s > m:
    print(-1)
else:
    print((s*s)-cnt)