def gcd(a,b):
    if b == 0:
        return a
    return gcd(b,a%b)
def lcm(a,b):
    return (a*b)//gcd(a,b)
t,w,b = map(int,input().split())
lc = lcm(w,b)
mn = 0
if w > b:
    mn = b
else:
    mn = w
ans = mn*(t//lc+1)-1
val = (t//lc)*lc + mn - 1
if t - val < 0:
    ans += t-val
g = gcd(ans,t)
ans //= g
t //= g
print(ans,end="")
print("/",end="")
print(t)