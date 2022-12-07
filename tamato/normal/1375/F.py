mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    a, b, c = map(int, input().split())
    X_ori = [a, b, c]
    X = sorted([a, b, c])
    mi = X[0]
    mid = X[1]
    ma = X[2]
    i_mi = X_ori.index(mi)
    i_mid = X_ori.index(mid)
    i_ma = X_ori.index(ma)
    print("First")
    sys.stdout.flush()
    x = mid - mi
    y = ma - mid
    print(x+2*y)
    sys.stdout.flush()
    j = int(input()) - 1
    if j == i_mi:
        print(y)
        sys.stdout.flush()
        _ = int(input())
        exit()
    elif j == i_mid:
        print(x+y)
        sys.stdout.flush()
        _ = int(input())
        exit()
    else:
        print(3*x + 6*y)
        sys.stdout.flush()
        j = int(input()) - 1
        if j == i_mi:
            print(x+3*y)
            sys.stdout.flush()
            _ = int(input())
            exit()
        else:
            print(2*x + 3*y)
            sys.stdout.flush()
            _ = int(input())
            exit()


if __name__ == '__main__':
    main()