a=raw_input()
ans = 0
for i in xrange(len(a)):
    if a[i] != 'A':
        continue
    L = 0
    for j in xrange(i):
        if a[j] == 'Q':
            L += 1
    for j in xrange(i + 1, len(a)):
        if a[j] == 'Q':
            ans += L
print ans