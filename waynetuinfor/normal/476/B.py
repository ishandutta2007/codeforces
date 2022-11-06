s1 = input()
s2 = input()
e = 0
for i in s1:
    if i == '+': e += 1
    else: e -= 1
    
maxn = 15
c = [[0 for i in range(maxn)] for j in range(maxn)]
c[0][0] = 1
for i in range(1, maxn):
    for j in range(maxn):
        c[i][j] = c[i - 1][j]
        if j > 0: c[i][j] += c[i - 1][j - 1]
        
e2 = 0
q = 0
for i in s2:
    if i == '+': e2 += 1
    elif i == '-': e2 -= 1
    else: q += 1

# print(q, e2 - e)
cnk = c[q][(q + abs(e2 - e)) // 2]
# print(cnk)
print("%0.20f" % (cnk / pow(2, q)))