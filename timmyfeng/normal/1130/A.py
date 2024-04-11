n = input()
a = map(int, raw_input().split())

pos, neg = 0, 0
for i in a:
    if i < 0:
        neg += 1
    elif i > 0:
        pos += 1

if pos >= (n + 1) / 2:
    print(1)
elif neg >= (n + 1) / 2:
    print(-1)
else:
    print(0)