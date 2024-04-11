n = int(input())

def get(t):
    t = t % 360
    return min(t, 360 - t)

mn = get(n)
cnt = 0
for i in range(4):
    x = n - 90 * i
    if mn > get(x):
        mn = get(x)
        cnt = i
print(cnt)