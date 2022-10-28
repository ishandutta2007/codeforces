n = input()
a = map(int, raw_input().split())

pos, neg, zero, ans = 0, 0, 0, 0
for i in a:
    if i > 0:
        ans += i - 1
        pos += 1
    elif i < 0:
        ans += -i - 1
        neg += 1
    else:
        zero += 1
        ans += 1

if neg % 2 == 1 and zero == 0:
    ans += 2

print ans