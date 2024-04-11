mod = 998244353


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        for i in range(1, N+1):
            line = [0] * i
            line[0] = 1
            line[-1] = 1
            print(*line)


if __name__ == '__main__':
    main()