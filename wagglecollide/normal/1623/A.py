from sys import stdin, stdout


def func(n, m, r_b, c_b, r_d, c_d):
    res = 0
    row, col = r_b, c_b
    pos = [row, col]

    x_dir = 1
    y_dir = 1
    while not pos[0] == r_d and not pos[1] == c_d:
        if pos[0] + x_dir > n:
            x_dir = -1
        elif pos[0] + x_dir < 1:
            x_dir = 1

        if pos[1] + y_dir > m:
            y_dir = -1
        elif pos[1] + y_dir < 1:
            y_dir = 1

        pos[0] += x_dir
        pos[1] += y_dir

        res += 1

    return res


t = int(stdin.readline())
for _ in range(t):
    n, m, r_b, c_b, r_d, c_d = map(int, stdin.readline().split())
    ans = func(n, m, r_b, c_b, r_d, c_d)
    stdout.write(str(ans) + '\n')