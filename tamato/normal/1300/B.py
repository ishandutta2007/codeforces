def main():
    import sys
    input = sys.stdin.readline

    t = int(input())
    for _ in range(t):
        N = int(input())
        A = list(map(int, input().split()))

        A.sort()
        print(A[N] - A[N-1])


if __name__ == '__main__':
    main()