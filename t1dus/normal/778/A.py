def possible(t,p,a,n):
    s = ''
    check = [True]*len(t)
    for i in range(n):
        check[a[i]] = False
    for i in range(len(check)):
        if check[i]:
            s += t[i]
    
    m = len(s)
    lp = len(p)
    c = 0
    for i in range(m):
        if s[i] == p[c]:
            c += 1
        if c == lp:
            return True
    return False        
    
t = input()
p = input()
a = list(map(int,input().split()))
for i in range(len(a)):
    a[i] -= 1

low = 0
high = len(a)
ans = 0
while low <= high:
    mid = (low+high)//2
    if possible(t,p,a,mid):
        ans = mid
        low = mid+1
    else:
        high = mid-1
print(ans)