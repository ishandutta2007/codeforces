s = raw_input()
h = int(s[0:2])
m = int(s[3:5])
ret = 0
while True:
    if h/10 == m%10 and h%10 == m/10:
        break
    m += 1
    if m == 60:
        m = 0
        h += 1
        if h == 24:
            h = 0
    ret += 1
print ret