a = raw_input()
L = [0] * (len(a) + 2)
R = [0] * (len(a) + 2)
for i in xrange(len(a)):
    L[i + 1] = L[i] + (a[i] == 'a')
for i in xrange(len(a) - 1, -1, -1):
    R[i + 1] = R[i + 2] + (a[i] == 'a')

ans = L[len(a)]
for i in xrange(0, len(a)):
    cnt = 0
    for j in xrange(i, len(a)):
        cnt += a[j] == 'b'
        ans = max(ans, cnt + L[i] + R[j + 2])
print ans