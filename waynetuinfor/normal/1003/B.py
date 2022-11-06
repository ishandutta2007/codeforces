a, b, x = map(int, input().split())
s = ""
ca = '0'
cb = '1'
if a > b:
    ca = '1'
    cb = '0'
    a, b = b, a
s += cb
c = ca
b -= 1
for i in range(x):
    s += c
    if c == ca: a -= 1
    else: b -= 1
    c = '1' if c == '0' else '0'
for i in range(len(s)):
    print(s[i], end='')
    if s[i] == cb:
        while b > 0:
            print(cb, end='')
            b -= 1
    else:
        while a > 0:
            print(ca, end='')
            a -= 1