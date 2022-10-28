x, y, z = map(int, raw_input().split())
bal = x - y

if z < abs(bal):
    print "+" if bal > 0 else "-"
elif bal == 0 and z == 0:
    print "0"
else:
    print "?"