n = int(input())
alpha = "abcdefghijklmnopqrstuvwxyz"
s = alpha
ind = 0
cur = 1
while n > 0:
    if cur > n:
        ind += 1
        cur = 1
    else:
        n -= cur
        cur += 1
        s += alpha[ind]
print(s)