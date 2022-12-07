a, b = map(int, input().split())
if a == 9 and b == 1:
    print(99, 100)
    exit()
if b - a > 1 or b - a < 0:
    print(-1)
elif b - a == 1:
    print(str(a) + '9', str(b) + '0')
else:
    print(str(a) + '8', str(b) + '9')