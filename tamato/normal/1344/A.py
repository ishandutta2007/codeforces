mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        AA = [(a + i) % N for i, a in enumerate(A)]
        if len(set(AA)) == N:
            print("YES")
        else:
            print("NO")


if __name__ == '__main__':
    main()