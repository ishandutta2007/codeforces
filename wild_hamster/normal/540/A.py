__author__ = 'WildHamster'
from math import fabs
n = int(input())
s = input()
t = input()
ans = 0
for i in range(n):
    ans = ans + min(abs(int(s[i])-int(t[i])),10-abs(int(s[i])-int(t[i])))
print(ans)