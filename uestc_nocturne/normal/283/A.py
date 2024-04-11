Max = 200100
d = [0] * Max
a = [0] * Max
cnt = 1
s = 0
n = (int)(raw_input())
for i in range(0, n):
    x = map(int, raw_input().split())
    if x[0] == 1:
        s += x[1] * x[2]
        x[1] -= 1
        d[x[1]] += x[2]
    elif x[0] == 2:
        a[cnt] = x[1]
        cnt += 1
        s += x[1]
    else:
        cnt -= 1
        d[cnt-1] += d[cnt]
        s -= a[cnt]
        s -= d[cnt]
        d[cnt] = 0
    print 1.0 * s / cnt