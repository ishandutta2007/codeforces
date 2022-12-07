def main():
    import sys
    input = sys.stdin.readline
    from collections import defaultdict

    # any 2 points must have different position.
    # 
    def ConvexHull(point_list):
        pos2idx = {point_list[i]: i for i in range(len(point_list))}
        y_val = defaultdict(list)
        x_list = sorted(list(set([p[0] for p in point_list])))
        for x, y in point_list:
            y_val[x].append(y)

        upper = [(x_list[0], max(y_val[x_list[0]]))]
        lower = [(x_list[0], min(y_val[x_list[0]]))]
        prev = float('inf')
        for xi in x_list[1:]:
            x0, y0 = upper[-1]
            x1, y1 = xi, max(y_val[xi])
            if (y1 - y0) / (x1 - x0) < prev:
                upper.append((x1, y1))
                prev = (y1 - y0) / (x1 - x0)
            else:
                while True:
                    x0, y0 = upper[-1]
                    if len(upper) == 1:
                        upper.append((x1, y1))
                        break
                    x00, y00 = upper[-2]
                    if (y1 - y0) / (x1 - x0) > (y1 - y00) / (x1 - x00):
                        upper.pop()
                    else:
                        prev = (y1 - y0) / (x1 - x0)
                        upper.append((x1, y1))
                        break

        prev = -float('inf')
        for xi in x_list[1:]:
            x0, y0 = lower[-1]
            x1, y1 = xi, min(y_val[xi])
            if (y1 - y0) / (x1 - x0) > prev:
                lower.append((x1, y1))
                prev = (y1 - y0) / (x1 - x0)
            else:
                while True:
                    x0, y0 = lower[-1]
                    if len(lower) == 1:
                        lower.append((x1, y1))
                        break
                    x00, y00 = lower[-2]
                    if (y1 - y0) / (x1 - x0) < (y1 - y00) / (x1 - x00):
                        lower.pop()
                    else:
                        prev = (y1 - y0) / (x1 - x0)
                        lower.append((x1, y1))
                        break

        # return upper, lower
        # return [pos2idx[xy] for xy in upper], [pos2idx[xy] for xy in lower]

        upper_idx, lower_idx = [pos2idx[xy] for xy in upper], [pos2idx[xy] for xy in lower]
        if upper_idx[-1] == lower_idx[-1]:
            upper_idx.pop()
        CH_idx = upper_idx
        CH_idx.extend(reversed(lower_idx))
        if CH_idx[0] == CH_idx[-1] and len(CH_idx) > 1:
            CH_idx.pop()
        return CH_idx

    N = int(input())
    if N % 2 == 1:
        print('NO')
        exit()
    point_list = []
    for _ in range(N):
        x, y = map(int, input().split())
        point_list.append((x, y))
    CH = ConvexHull(point_list)

    for i in range(N):
        x1, y1 = point_list[i]
        x2, y2 = point_list[(i+1)%N]
        dx = x2 - x1
        dy = y2 - y1
        X1, Y1 = point_list[(i + (N//2))%N]
        X2, Y2 = point_list[(i + 1 + (N//2)) % N]
        dX = X2 - X1
        dY = Y2 - Y1
        if dx != -dX or dy != -dY:
            print('NO')
            exit()
    print('YES')


if __name__ == '__main__':
    main()