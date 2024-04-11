import sys
range = xrange
input = raw_input
al = 26

s = [ ord(x) - ord('a') for x in input() ]
q = int(input())

st = [0] * 2 * len(s)

def upd(a, val):
    a += len(s)
    st[a] = 1 << val
    a //= 2
    while a > 0:
        st[a] = st[a * 2] | st[a * 2 + 1]
        a //= 2

def qry(a, b):
    a += len(s)
    b += len(s)
    res = 0
    while a <= b:
        if a % 2 == 1:
            res |= st[a]
            a += 1
        if b % 2 == 0:
            res |= st[b]
            b -= 1
        a //= 2
        b //= 2
    return bin(res).count('1')

for i in range(len(s)):
    upd(i, s[i])

for _ in range(q):
    a, b, c = input().split()

    if int(a) == 1:
        upd(int(b) - 1, ord(c) - ord('a'))
    else:
        print qry(int(b) - 1, int(c) - 1)