from math import factorial as f 
def ncr(n,r):
    if n < r: return 0
    return f(n)//(f(n-r)*f(r))

s1 = input()
s2 = input()
cnt1 = cnt2 = cnt3 = 0
for i in s1:
    if i == '+': cnt1 += 1 
    else: cnt1 -= 1
for i in s2:
    if i == '+': cnt2 += 1 
    elif i == '-': cnt2 -= 1 
    else: cnt3 += 1
nd = abs(cnt2-cnt1)
"""
let x = number of '+'
let y = cnt3
2*x = nd+cnt3
"""
x = (nd+cnt3)/2
# print(x,cnt3,nd)
if x != int(x): print(0)
else: print(ncr(cnt3,x)/(1<<cnt3))