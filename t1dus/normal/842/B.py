def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
def incrust(d,r,dist):
    return r-d <= dist and dist <= r 
    
from math import sqrt    
    
r,d = map_input()
n = int(input())
ans = 0
for i in range(n):
    x,y,z = map_input()
    if incrust(d,r,sqrt(x**2+y**2)+z) and incrust(d,r,sqrt(x**2+y**2)-z):
        ans += 1 
        # print(i)
print(ans)