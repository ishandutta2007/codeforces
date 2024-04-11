x = eval(input())
y = x
while y >= 10:
    y //= 10
if y < 8:
    cur=3
    print("-[----->+<]>",end="")
else:
    cur=9
    print("+[--------->+<]>",end="")
if x >= 100:
    tmp = x//100
    s = "."
    if tmp > cur:
        s = "+"*(tmp-cur)+s
    if tmp < cur:
        s = "-"*(cur-tmp)+s
    cur = tmp
    print(s, end="")
x %= 100
if x >= 10:
    tmp = x//10
    s = "."
    if tmp > cur:
        s = "+"*(tmp-cur)+s
    if tmp < cur:
        s = "-"*(cur-tmp)+s
    cur = tmp
    print(s, end="")
x %= 10
tmp = x
s = "."
if tmp > cur:
    s = "+"*(tmp-cur)+s
if tmp < cur:
    s = "-"*(cur-tmp)+s
cur = tmp
print(s, end="")