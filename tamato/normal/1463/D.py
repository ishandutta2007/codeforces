mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N = int(input())
        B = set(map(int, input().split()))

        ma = 0
        small = 0
        for i in range(1, 2*N+1):
            if i in B:
                small += 1
            else:
                if small > 0:
                    small -= 1
                    ma += 1

        mi = N
        big = 0
        for i in range(2*N, 0, -1):
            if i in B:
                big += 1
            else:
                if big > 0:
                    big -= 1
                    mi -= 1

        print(ma - mi + 1)


if __name__ == '__main__':
    main()