mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))
        S = sum(A)

        if S % N != 0:
            print(-1)
            continue

        aa = S // N
        ans = []
        for i in range(2, N+1):
            ans.append((1, i, (-A[i-1]) % i))
            ans.append((i, 1, (A[i-1] - 1) // i + 1))
        for i in range(2, N+1):
            ans.append((1, i, aa))
        print(len(ans))
        for i, j, x in ans:
            print(i, j, x)


if __name__ == '__main__':
    main()