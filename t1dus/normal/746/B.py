n = int(input())
s = list(input())
a = ['']*n
if n%2 == 0:
    x = n//2
    x -= 1
    for i in range(n//2):
        q = s[2*i]
        w = s[2*i+1]
        a[x-i] = q
        a[x+1+i] = w
else:
    x = n//2
    a[x] = s[0]
    for i in range(1,x+1):
        a[x-i] = s[2*i-1]
        a[x+i] = s[2*i]
print("".join(a))