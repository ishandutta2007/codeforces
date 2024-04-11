n = input()
ret = []
x = 2
while x <= n:
    ret.append(x)
    x += 2
x = 1
while x <= n:
    ret.append(x)
    x += 2
x = 2
while x <= n:
    ret.append(x)
    x += 2
print len(ret)
print " ".join([str(x) for x in ret])