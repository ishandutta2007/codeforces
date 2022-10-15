import random
random.seed()

def query(i):
    print('? {}'.format(i), flush=True)
    v, nxt = map(int, input().split())
    return v, nxt

def answer(x):
    print('! {}'.format(x), flush=True)
    exit()

n, start, x = map(int, input().split())

nxt = start
opt = -1

for i in range(1000):
    vcur, nxtcur = query(random.randrange(1, n + 1))
    if vcur < x and vcur > opt:
        opt = vcur
        nxt = nxtcur

while nxt != -1:
    vcur, nxtcur = query(nxt)
    opt = vcur
    nxt = nxtcur
    if opt >= x:
        break

if opt < x:
    opt = -1

answer(opt)