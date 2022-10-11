a = raw_input()
b = raw_input()

c = raw_input()
s = ""
for i in xrange(len(c)):
    upper = c[i] in 'QWERTYUIOPASDFGHJKLZXCVBNM'
    lower = c[i] in 'qwertyuiopasdfghjklzxcvbnm'
    if not upper and not lower:
        s += c[i]
    else:
        for j in xrange(len(a)):
            if c[i].lower() == a[j]:
                if upper:
                    s += b[j].upper()
                else:
                    s += b[j].lower()
print s