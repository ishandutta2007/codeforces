s = input()
a = [0] * 26
for c in s:
    a[ord(c)-ord('a')] += 1
x = 0
y = 25
while x < y:
    while x < y and a[x] % 2 == 0:
        x += 1
    while x < y and a[y] % 2 == 0:
        y -= 1
    if x < y:
        a[x] += 1
        a[y] -= 1
        x += 1
        y -= 1
r = ''
middle = ''
for i in range(26):
    c = str(chr(i + ord('a')))
    r += c * (a[i] // 2)
    if a[i] % 2 == 1:
        middle = c
print(r + middle + r[::-1])