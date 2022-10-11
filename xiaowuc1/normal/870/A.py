raw_input()
a = raw_input()
b = raw_input()
ret = 0
while True:
    valid = False
    for x in str(ret):
        if x in a:
            valid = True
    if not valid:
        ret += 1
        continue
    valid = False
    for x in str(ret):
        if x in b:
            valid = True
    if not valid:
        ret += 1
        continue
    print ret
    break