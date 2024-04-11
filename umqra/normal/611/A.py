import datetime

a, b, c = input().split()
a = int(a)
ans = 0
for i in range(1, 13):
    for s in range(1, 32):
        try:
            x = datetime.datetime(2016, i, s)
            if c == 'week' and x.weekday() == a - 1:
                ans += 1
            if c == 'month' and s == a:
                ans += 1
        except:
            pass
print(ans)