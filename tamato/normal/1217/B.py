def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N, x = map(int, input().split())
        D = []
        H = []
        H_D = []
        for _ in range(N):
            d, h = map(int, input().split())
            D.append(d)
            H.append(h)
            H_D.append(d-h)
        if max(D) >= x:
            print(1)
            continue
        elif max(H_D) <= 0:
            print(-1)
            continue
        print((x - max(D) - 1) // max(H_D) + 1 + 1)


if __name__ == '__main__':
    main()