for _ in range(int(input())):
    x_min = -100000
    x_max = 100000
    y_min = -100000
    y_max = 100000
    for _ in range(int(input())):
        x, y, left, up, right, down = map(int, input().split())
        if not left:
            x_min = max(x_min, x)
        if not up:
            y_max = min(y_max, y)
        if not right:
            x_max = min(x_max, x)
        if not down:
            y_min = max(y_min, y)
    if x_min <= x_max and y_min <= y_max:
        print("1 " + str(x_min) + " " + str(y_min))
    else:
        print("0")