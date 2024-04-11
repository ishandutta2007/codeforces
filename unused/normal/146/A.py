raw_input()
a=raw_input()
for c in a:
    if c != '4' and c != '7':
        print 'NO'
        exit()
b=[int(x) for x in a]
if sum(b)  == sum(b[:len(b)/2]) * 2:
    print 'YES'
else:
    print 'NO'