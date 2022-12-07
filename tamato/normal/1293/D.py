def main():
    import sys
    input = sys.stdin.readline

    def dist(x1, y1, x2, y2):
        return abs(x1-x2) + abs(y1-y2)

    x0, y0, ax, ay, bx, by = map(int, input().split())
    xs, ys, t = map(int, input().split())

    xy_list = [(x0, y0)]
    x, y = x0, y0
    while True:
        x, y = ax * x + bx, ay * y + by
        if dist(xs, ys, x, y) > t and x > xs and y > ys:
            break
        xy_list.append((x, y))
    N = len(xy_list)

    ans = 0
    for j in range(N):
        for k in range(j, N):
            xj, yj = xy_list[j]
            xk, yk = xy_list[k]
            if dist(xs, ys, xj, yj) + dist(xj, yj, xk, yk) <= t:
                ans = max(ans, k-j+1)
            if dist(xs, ys, xk, yk) + dist(xj, yj, xk, yk) <= t:
                ans = max(ans, k-j+1)
    print(ans)


if __name__ == '__main__':
    main()