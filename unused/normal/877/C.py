ans = []
ans2 = []

def x(l, r):
    while l <= r:
        if l == r:
            ans.append(l)
            break
        elif l < r:
            ans.append(l + 1)
            ans2.append(l + 1)
            ans2.append(l)
            l += 2

a=input()
x(1, a)
ans += ans2[::-1]
print len(ans)
print ' '.join([str(x) for x in ans])