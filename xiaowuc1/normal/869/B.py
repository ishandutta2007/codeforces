a, b = (int(x) for x in raw_input().split())
ret = 1
i = a+1
while i <= b:
    ret *= i
    ret %= 10
    if ret == 0:
        break
    i += 1
print ret