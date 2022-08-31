def cnt(a, n):
    k = len(a)
    ret = 0
    s2 = 0
    s = 0
    for x in a:
        s2+=x*x
        s+=x
    ret -= (s*s-s2)//2
    for i in range(k):
        ret-=i*a[i]
        ret += (k-1-i)*a[i]*n
    ret+=k*(k-1)//2 * n
    return ret

t = int(input())
for ir in range(t):
    n = int(input())
    a = []
    b=  dict()
    s = input().split(' ')
    for x in range(n):
        u = int(s[x])
        if u not in b:
            b[u] = []
        b[u].append(x)
    ans = 0
    for x in b:
        ans += cnt(b[x], n)
    print(ans)