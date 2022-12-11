A = map(int, raw_input().split())

cycles = [
    [13,14,5,6,17,18,21,22],
    [15,16,7,8,19,20,23,24],
    [1,3,5,7,9,11,24,22],
    [2,4,6,8,10,12,23,21],
    [3,4,17,19,10,9,16,14],
    [1,2,18,20,12,11,15,13]
]

for x in cycles:
    for y in xrange(len(x)):
        x[y] -= 1

for cycle in cycles:
    a = list(A)
    for i in xrange(2):
        x = a[cycle[i]]
        for j in xrange(len(cycle) / 2 - 1):
            a[cycle[i + j * 2]] = a[cycle[i + j * 2 + 2]]
        a[cycle[-2+i]] = x
    wrong = False
    for i in xrange(0, len(a), 4):
        for j in xrange(3):
            if a[i] != a[i + j + 1]:
                wrong = True
                break
        if wrong:
            break
    if wrong == False:
        print 'YES'
        exit()

for cycle in cycles:
    cycle = cycle[::-1]

for cycle in cycles:
    a = list(A)
    for i in xrange(2):
        x = a[cycle[i]]
        for j in xrange(len(cycle) / 2 - 1):
            a[cycle[i + j * 2]] = a[cycle[i + j * 2 + 2]]
        a[cycle[-i-1]] = x
    wrong = False
    for i in xrange(0, len(a), 4):
        for j in xrange(3):
            if a[i] != a[i + j + 1]:
                wrong = True
                break
        if wrong:
            break
    if wrong == False:
        print 'YES'
        exit()

print 'NO'