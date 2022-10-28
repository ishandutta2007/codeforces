import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

class BIT():
    def __init__(self, a, partial, l, r):
        self.a = a
        self.l = l
        self.r = r
        self.mid = (l + r) // 2
        self.tot = partial[r] - partial[l]
        if r - l == 1:
            self.left = None
            self.right = None
        else:
            self.left = BIT(a, partial, self.l, self.mid)
            self.right = BIT(a, partial, self.mid, self.r)

    def add(self, ind):
        self.tot += 1
        if self.r - self.l > 1:
            if ind < self.mid:
                self.left.add(ind)
            else:
                self.right.add(ind)
        else:
            self.a[ind] += 1

    def sub(self, ind):
        self.tot -= 1
        if self.r - self.l > 1:
            if ind < self.mid:
                self.left.sub(ind)
            else:
                self.right.sub(ind)
        else:
            self.a[ind] -= 1

    def partial(self, ind):
        if self.r - self.l == 1:
            if ind == self.r:
                return self.tot
            else:
                return 0
        if ind <= self.mid:
            return self.left.partial(ind)
        else:
            return self.left.tot + self.right.partial(ind)

facs = [1]
M = 998244353
for i in range(1, 200001):
    facs.append(facs[-1] * i % M)
ifacs = [pow(facs[-1], M - 2, M)]
for i in range(200000, 0, -1):
    ifacs.append(ifacs[-1] * i % M)
ifacs = ifacs[::-1]

n, m = I()
s = I()
t = I()
s = [guy - 1 for guy in s]
t = [guy - 1 for guy in t]
ss = len(s)
tt = len(t)
count = [0] * 200000
for guy in s:
    count[guy] += 1
partial = [0]
for i in range(200000):
    partial.append(partial[-1] + count[i])
bit = BIT(count, partial, 0, 200000)

perms = facs[ss]
for guy in count:
    perms = perms * ifacs[guy] % M

tot = 0
for i in range(tt):
    if i >= ss:
        tot += 1
        break
    #print(tot)
    perms = (perms * pow(ss - i, M - 2, M)) % M
    x = t[i]
    low = bit.partial(x)
    #print(low, x, count[:5])
    tot = (tot + perms * low) % M
    if count[x] == 0:
        break
    else:
        perms = (perms * count[x]) % M
        bit.sub(x)
        #print(count[:5])

print(tot % M)