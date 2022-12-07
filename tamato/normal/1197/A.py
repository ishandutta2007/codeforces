mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))
        A.sort()
        print(min(N - 2, A[-2] - 1))


if __name__ == '__main__':
    main()