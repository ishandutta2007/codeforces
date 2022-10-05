for _ in range(int(input())):
    b, w = map(int, input().split())
    y = 2
    if w > b:
        y = 3
        b, w = w, b
    if b > (3 * w) + 1:
        print("NO")
        continue
    print("YES")
    if b > w:
        print("1 " + str(y))
        b -= 1
    for x in range(2, (2 * w) + 2, 2):
        print(str(x) + " " + str(y))
    for x in range(3, (2 * min(b, w)) + 3, 2):
        print(str(x) + " " + str(y))
    y += 1
    for x in range(2, (2 * min(b - w, w)) + 2, 2):
        print(str(x) + " " + str(y))
    y -= 2
    for x in range(2, (2 * (b - (2 * w))) + 2, 2):
        print(str(x) + " " + str(y))