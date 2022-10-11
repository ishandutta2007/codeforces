l = raw_input()
n = int(raw_input()) % 4
alpha = "v<^>"
if n == 0 or n == 2:
    print "undefined"
else:
    orig = 0
    while alpha[orig] != l[0]:
        orig += 1
    now = 0
    while alpha[now] != l[2]:
        now += 1
    if (orig+n)%4 == now:
        print "cw"
    elif (orig-n+8)%4 == now:
        print "ccw"
    else:
        print "undefined"