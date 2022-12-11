def m(z):
    r = '0'
    for c in z:
        if c == '4' or c == '7':
            r += c
    return int(r)
    
a, b = map(int, raw_input().split())
while True:
    a += 1
    if m(str(a)) == b:
        print a
        break