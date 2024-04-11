from sys import stdout

def gcd(a, b):
    return gcd(b, a % b) if b else a

n = input()
dat = map(int, raw_input().split())
g = 0
for t in dat:
    g = gcd(g, t)
if not g in dat:
    print '-1'
    exit()
print n * 2 - 1

for i in xrange(n):
    if i:
        stdout.write('%d ' % g)
    stdout.write('%d ' % dat[i])
print ''