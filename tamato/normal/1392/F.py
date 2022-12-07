mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    N = int(input())
    A = list(map(int, input().split()))
    S = sum(A)

    k = (S - (N-1) * (N-2) // 2) % N
    x = (S - (N-1) * (N-2) // 2 - k) // N
    for i in range(N-1):
        sys.stdout.write(str(x + i) + " ")
        if i == k:
            sys.stdout.write(str(x + i) + " ")
    if k == N-1:
        sys.stdout.write(str(x + k) + " ")


if __name__ == '__main__':
    main()